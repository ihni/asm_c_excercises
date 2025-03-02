#include <stdio.h>

// writing strlen strcat and strcmp
// on my own for practice
// also including my own readline func
//
int readline(char *s, const int n);
int strlenv(char *s);
void strcatv(char *s1, const char *s2);
int strcmpv(const char *s1, const char *s2);

int readline(char *s, const int n) {
    int count = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        if (count < n) {
            *s++ = ch;
            count++;
        }
    }
    return count;
}

int strlenv(char *s) {
    char *p = s;
    while (*p++)
        ;
    return p - s - 1;
}

void strcatv(char *s1, const char *s2) {
    char *p = s1;
    while (*p) { // p should be on the null char
        p++;
    }
    while((*p++ = *s2++))
        ;
    *p = '\0';
}

int strcmpv(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}


int main(void) {
    char s[50] = "cat";
    char x[50] = "zat";

    if (strcmpv(s, x) > 0) {
        printf("%s is larger than %s\n", s, x);
    } else if (strcmpv(s, x) < 0) {
        printf("%s is larger than %s\n", x, s);
    } else {
        printf("%s is equal to %s\n", s, x);
    }

    printf("\n%s is len %d\n", s, strlenv(s));
    printf("%s is len %d\n", x, strlenv(x));
    
    strcatv(s, x);
    printf("\nConcatinating them together: %s\n", s);
    printf("\n%s is len %d\n", s, strlenv(s));

    return 0;
}
