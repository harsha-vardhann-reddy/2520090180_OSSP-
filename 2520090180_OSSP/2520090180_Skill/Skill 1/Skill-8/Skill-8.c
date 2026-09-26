#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expand_variable(char *var) {
    char *value = getenv(var);

    if (value != NULL)
        printf("%s = %s\n", var, value);
    else
        printf("%s is undefined\n", var);
}

int main() {
    char input[100];

    printf("Enter variable name: ");
    scanf("%s", input);

    expand_variable(input);

    return 0;
}
