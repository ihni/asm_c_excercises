#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool are_anagrams(const char *s1, const char *s2);

bool are_anagrams(const char *s1, const char *s2) {
    // to figure out if a word is an anagram of another
    // we will take the ascii sum of the first word
    // then subtract each char from the second
    // if by the end we're left with 0, it is an anagram
    // else it's not an anagram
    //
    // scrap that this is wrong:
    // ad and bc are anagrams according to this
    // will fix tmr
    int sum = 0;
    while (*s1) {
        sum += *s1++;
    }

    while (*s2) {
        sum -= *s2++;
    }

    if (sum) {
        return false;
    } else {
        return true;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Please enter two words as arguments\n");
        return 0;
    }

    if (are_anagrams(argv[1], argv[2])) {
        printf("'%s' and '%s' are anagrams\n", argv[1], argv[2]);
    } else {
        printf("'%s' and '%s' are NOT anagrams\n", argv[1], argv[2]);
    }

    return 0;
}
