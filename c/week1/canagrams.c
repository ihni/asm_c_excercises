#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

char* to_lower(char *c);
bool is_word(char *s);
bool are_anagrams(const char *s1, const char *s2);

char* to_lower(char *c) {
    if (*c >= 0x41 && *c <= 0x5a) {
        *c += 0x20;
    }
    return c;
}

bool is_word(char *s) {
    while (*to_lower(s)) {
        if (*s < 0x61 || *s > 0x7a) {
            return false;
        }
        s++;
    }
    return true;
}

bool are_anagrams(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    
    int sum[26] = {0};
    // stores the value alphabetically in order
    // based off ascii code(lower case letters)
    // minus 0x61 to make a equal 0 index
    while (*s1) {
        sum[*s1++ - 0x61]++;
        sum[*s2++ - 0x61]--;
    }
    
    for (int *i = sum; i < sum + 26; i++) {
        if (*i)
            return false;
    }
    return true;
}

int main(int argc, char **argv) {
    bool valid = true;
    if (argc < 3) {
        printf("Please enter two words as arguments\n");
        return 0;
    }

    char *s1 = argv[1];
    char *s2 = argv[2];
    
    if (!(is_word(s1) && is_word(s2))) {
        printf("error, expected a word (only letters)\n");
        exit(1);
    }

    if (are_anagrams(argv[1], argv[2])) {
        printf("'%s' and '%s' are anagrams\n", argv[1], argv[2]);
    } else {
        printf("'%s' and '%s' are NOT anagrams\n", argv[1], argv[2]);
    }

    return 0;
}
