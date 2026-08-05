#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char command[100];
    pid_t pid;

    printf("Enter Linux command: ");
    scanf("%s", command);

    pid = fork();

    if (pid < 0)
    {
        printf("Error: Unable to create child process.\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child Process
        printf("\n----- Child Process -----\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        execlp(command, command, NULL);

        // Executes only if execlp() fails
        perror("Command execution failed");
        exit(1);
    }
    else
    {
        // Parent Process
        printf("\n----- Parent Process -----\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        wait(NULL);

        printf("\nChild process completed successfully.\n");
    }

    return 0;
}
