#include <stdio.h>
#include "readline.h"

#define LEN 256

int main(int argc, char *argv[]) {
    char buffer[LEN];

    printf("Enter a sentence: ");
    readline(buffer, LEN);
    
    // set ptr to the end of buffer
    // so i can stdout the string in reverse
    char *ptr = buffer;
    while (*ptr++)
        ;

    printf("In reverse:\n");
    while (ptr-- > buffer) {
        printf("%c", *ptr);
    }
    printf("\n");

    return 0;
}
