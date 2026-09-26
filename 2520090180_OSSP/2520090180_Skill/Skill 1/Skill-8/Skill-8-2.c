#include <stdio.h>
#include <string.h>

int count = 0;

void show() {
    printf("Built-in command executed.\n");
}

void increment() {
    count++;
    printf("Count = %d\n", count);
}

void reset() {
    count = 0;
    printf("Count reset to 0\n");
}

int main() {
    char command[50];

    printf("Enter command: ");
    scanf("%s", command);

    if (strcmp(command, "show") == 0) {
        show();
    }
    else if (strcmp(command, "increment") == 0) {
        increment();
    }
    else if (strcmp(command, "reset") == 0) {
        reset();
    }
    else {
        printf("Invalid command\n");
    }

    return 0;
}
