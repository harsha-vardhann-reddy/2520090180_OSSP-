#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        return 5;
    }

    int status;

    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
        printf("Child exited with status: %d\n",
               WEXITSTATUS(status));

    return 0;
}
