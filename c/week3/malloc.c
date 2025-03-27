#include <stdio.h>
#include <stdlib.h>

int *create_arr(int size);

int main(int argc, char *argv[]) {
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int *arr = create_arr(size);

    for (int *i = arr; i < arr + size; i++)
        *i = *(i-1) + 1;

    for (int *i = arr; i < arr + size; i++)
        printf("value at %p: %d\n", i, *i);

    return 0;
}

int *create_arr(int size) {
    int *arr = malloc(sizeof(int) * size);
    if (arr == NULL) {
        printf("malloc returned null pointer\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}
