#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    /* args[] = {"./picosat", "formula.cnf", "-a", argv[1], "-a", "argv[2]", ..., NULL} */
    
    int argslen = (argc - 1) * 2 + 3;
    char *args[argslen];
    args[0] = "./picosat";
    args[1] = "formula.cnf";
    int argsidx = 2;
    for (int i = 1; i < argc; i++)
    {
        args[argsidx] = "-a";
        args[argsidx + 1] = argv[i];
        argsidx += 2;
    }
    args[argslen - 1] = NULL;

    /* ./picosat formula.cnf -a argv[1] ... | ./sudoku_ui */

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Error during pipe creation\n");
        exit(-1);
    }

    int pid = fork();
    if (pid < 0)
    {
        perror("Error during child creation\n");
        return 0;
    }
    
    if (pid == 0) // Child 1 (solve sudoku)
    {
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execv("./picosat", args);
    }

    close(fd[1]);

    pid = fork();
    if (pid < 0)
    {
        perror("Error during child creation\n");
        return 0;
    }

    if (pid == 0) // Child 2 (format solution)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        execlp("./sudoku_ui", "./sudoku_ui", NULL);
    }

    close(fd[0]);

    wait(NULL);
    wait(NULL);
}