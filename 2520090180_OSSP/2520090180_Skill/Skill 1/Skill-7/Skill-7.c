#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process running...\n");
        sleep(2);
        printf("Child process finished.\n");
    } else {
        printf("Parent waiting for child...\n");
        waitpid(pid, NULL, 0);
        printf("Parent continues.\n");
    }

    return 0;
}
