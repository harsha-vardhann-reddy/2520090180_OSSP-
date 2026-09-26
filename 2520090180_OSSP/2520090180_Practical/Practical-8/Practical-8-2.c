#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 1000000

int main() {
    int *data = malloc(SIZE * sizeof(int));

    if (data == NULL) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
        data[i] = 1;

    printf("Memory allocated and initialized.\n");
    printf("Parent PID: %d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        free(data);
        return 1;
    }

    if (pid == 0) {
        printf("\nChild process created.\n");
        printf("Child PID: %d\n", getpid());

        printf("Modifying child memory...\n");

        for (int i = 0; i < SIZE; i++)
            data[i] = 2;

        printf("Child memory modified.\n");

        sleep(5);

        free(data);
        exit(0);
    }
    else {
        printf("\nParent process continues.\n");
        printf("Parent PID: %d\n", getpid());

        sleep(2);

        printf("Parent waits for child...\n");
        wait(NULL);

        printf("Child finished.\n");

        free(data);
    }

    return 0;
}
