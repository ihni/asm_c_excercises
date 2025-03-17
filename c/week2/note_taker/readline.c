#include <stdio.h>
#include <ctype.h>
#include "readline.h"

int readline(char *buff, int n) {
    int ch, count = 0;
    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF) {
        if (count < n)
            *(buff + count++) = ch;
        ch = getchar();
    }
    *(buff + count) = '\0';
    return count;
}

