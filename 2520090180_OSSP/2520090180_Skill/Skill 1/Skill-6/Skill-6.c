#include <stdio.h>
#include <string.h>
#include <ctype.h>

void parse_command(char *input) {
    char output[200];
    int i = 0, j = 0;
    int escaped = 0;

    while (input[i] != '\0') {
        if (escaped) {
            output[j++] = input[i];
            escaped = 0;
        }
        else if (input[i] == '\\') {
            escaped = 1;
        }
        else {
            output[j++] = input[i];
        }
        i++;
    }

    output[j] = '\0';
    printf("Parsed Output: %s\n", output);
}

int main() {
    char input[200];

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("\nOriginal Input: %s\n", input);

    parse_command(input);

    printf("Parser validation completed.\n");

    return 0;
}
