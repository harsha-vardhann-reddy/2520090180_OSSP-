#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[] = "Harsha";

    printf("----- Single Quotes -----\n");
    printf("Hello $name\n");
    printf("Today is $(date)\n");

    printf("\n----- Double Quotes -----\n");
    printf("Hello %s\n", name);

    printf("\n----- Preserve Spaces -----\n");
    printf("Hello     World\n");

    printf("\n----- Stored Strings -----\n");
    char single[] = "This is $name";
    printf("%s\n", single);

    printf("This is %s\n", name);

    printf("\n----- Command Execution -----\n");
    system("echo Current directory: $(pwd)");

    printf("\n----- Edge Cases -----\n");
    printf("Hello \"World\"\n");
    printf("Hello 'World'\n");
    printf("Cost is $100\n");

    return 0;
}
