#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{   
    char *path = "./picosat";
    argv[0] = path;
    argv[argc] = NULL;
    
    int fd[2];

    if (pipe(fd)==-1) 
	{
		perror("Pipe creation:"); 
		exit(-1); 
	}

    int id = fork();
    switch (id)
    {
    case -1: /* Erro handling */
        perror("Error al crear el proceso hijo");
        exit(1);
        break;
    case 0: /* Child */ 
        /* Redirecciono la entrada del hijo al desc. lectura del pipe */
        close(0);
        dup(fd[0]);
        
        /* Cerramos descriptores no utilizados */
        close(fd[1]);
        close(fd[0]); 

        execlp("./sudoku_ui", "./sudoku_ui", NULL);
        exit(-1);
        break;
    default: /* Parent */
        /* cerramos los descriptores que no vayamos a utilizar */
        close(1);
        dup(fd[1]);
        
        /* cerramos los descriptores que no vayamos a utilizar */
        close(fd[0]);
        close (fd[1]);
        
        /* Recubrimiento */
        execv(path, argv);
        exit(-1);
    }
}