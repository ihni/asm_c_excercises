#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20 // max letters that a word can be inputted
#define WORD_MIN_QUIT 4 // if a word with 4 letters is inputted, program terminates
                        // and displays smallest word & largest word

// read line works by storing to a pointer
// until '\n' is found and manually adds '\0'
// at the end
int read_line(char *buff);

int read_line(char *buff) {
    int count = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        if (count < MAX_WORD_LEN) {
            *buff++ = ch;
            count++;
        }
    }
    *buff = '\0';
    return count;
}

int main(int argc, char **argv) {
    char smallest_word[MAX_WORD_LEN] = {'\0'};
    char largest_word[MAX_WORD_LEN] = {'\0'};
    char buff[MAX_WORD_LEN];
    int count;

    printf("Enter word: ");
    count = read_line(buff);

    // initializing smallest and largest word to the first
    // word inputted
    strcpy(smallest_word, buff);
    strcpy(largest_word, buff);

    while (count != WORD_MIN_QUIT) {
        printf("Enter word: ");
        count = read_line(buff);
        if (strcmp(buff, smallest_word) <= 0) {
            strcpy(smallest_word, buff);
        } else if (strcmp(buff, largest_word) >= 0) {
            strcpy(largest_word, buff);
        }
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
    return 0;
}
