#include <stdio.h>
#include "readline.h"

int readline(char *s, int n) {
    int ch, count = 0;
    while ((ch = getchar()) != '\n') {
        if (count < n)
            *(s + count++) = ch;
    }
    *(s + count) = '\0';
    return count;
}
