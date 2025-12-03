#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main ()
{
    pid_t pid;
    int status;

    printf ("Parent PID: %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        /* Child Process */
        printf("Child PID: %d. Executing 'ls -l'...\n", getpid());
        execlp("ls", "ls", "-l", NULL);
        /* execlp hanya akan kembali jika gagal */
        perror("execlp failed");
        exit(1);
    }
    else {
        /* Parent Process */
        printf("Parent is waiting for child %d to finish.\n", pid);
        wait(&status); /* Parent menunggu proses anak selesai */

        if (WIFEXITED(status)) {
            printf("Child %d finished with status %d.\n", pid, WEXITSTATUS(status));
        }
        printf("Parent continues execution after child completion.\n");
    }

    return 0;
}
