#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2;

    // malloc()
    ptr1 = (int *)malloc(5 * sizeof(int));
    if (ptr1 == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
        ptr1[i] = i + 1;

    printf("Memory allocated using malloc()\n");

    // calloc()
    ptr2 = (int *)calloc(5, sizeof(int));
    if (ptr2 == NULL) {
        printf("calloc failed\n");
        free(ptr1);
        return 1;
    }

    printf("Memory allocated using calloc()\n");

    // realloc()
    ptr1 = (int *)realloc(ptr1, 10 * sizeof(int));
    if (ptr1 == NULL) {
        printf("realloc failed\n");
        free(ptr2);
        return 1;
    }

    printf("Memory resized using realloc()\n");

    // Free memory
    free(ptr1);
    free(ptr2);

    printf("Memory freed successfully\n");

    return 0;
}
