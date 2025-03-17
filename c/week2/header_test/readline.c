#include <stdio.h>
#include "readline.h"

int readline(char *buff, int n) {
    int ch;
    int count = 0;
    while ((ch = getchar()) != '\n') {
        if (count < n) {
            *buff++ = ch;
            count++;
            printf("%p : %c\n", buff, ch);
        }
    }
    *buff = '\0';
    printf("%p : %c\n", buff, *buff);
    return count;
}
