#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent process started.\n");

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child process created.\n");
        printf("Child PID: %d\n", getpid());

        char *args[] = {"ls", "-l", NULL};

        printf("Executing ls -l...\n");

        execvp(args[0], args);

        perror("Execution failed");
        exit(1);
    }
    else {
        printf("Parent waiting for child...\n");

        wait(NULL);

        printf("Child process completed.\n");
        printf("Parent process completed.\n");
    }

    return 0;
}
