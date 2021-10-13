#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    /*
    Args[] creation with structure:
    {"./picosat", "formula.cnf", "-a", argv[1], "-a", "argv[2]", ..., NULL}
    */
    int argsLength = (argc - 1) * 2 + 3;
    char *args[argsLength];
    args[0] = "./picosat";
    args[1] = "formula.cnf";
    int argsIndex = 2;
    for (int i = 1; i < argc; i++)
    {
        args[argsIndex] = "-a";
        args[argsIndex + 1] = argv[i];
        argsIndex += 2;
    }
    args[argsLength - 1] = NULL;

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("An error ocurred with opening the pipe\n");
        exit(-1);
    }

    int pid1 = fork();
    if (pid1 < 0)
    {
        perror("Error during child creation\n");
        return 0;
    }

    if (pid1 == 0) // Child (solve sudoku)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execv("./picosat", args);
    }

    int pid2 = fork();
    if (pid2 < 0)
    {
        perror("Error during child creation\n");
        return 0;
    }

    if (pid2 == 0) // Child (print solution)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("./sudoku_ui", "./sudoku_ui", NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}