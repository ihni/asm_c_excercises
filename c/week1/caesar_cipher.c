#include <stdio.h>

#define MAX_MSG_LEN 256

void encrypt(char *message, int shift);

void encrypt(char *message, int shift) {
    // encrypt will only shift characters
    // it will skip past special chars & numbers
    while (*message) {
        int shift_buff = shift;
        if (*message >= 'a' && *message <= 'z') {
            if ((*message + shift) > 'z')
                shift_buff = *message + shift - 25;
            *message += shift_buff;
         } else if (*message >= 'A' && *message <= 'Z') {
            if ((*message + shift) > 'Z')
                shift_buff = *message + shift - 25;
            *message += shift_buff;
        }
        message++;
    }
}

int readline(char *s);

int readline(char *s) {
    int count = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        if (count < MAX_MSG_LEN) {
            count++;
            *s++ = ch;
        }
    }
    *s = '\0';
    return count;
}

int main(void) {
    char message[MAX_MSG_LEN];
    int shift;

    printf("Enter a message to be encrypted: ");
    readline(message);

    printf("Enter a shift amount: ");
    scanf(" %d", &shift);

    encrypt(message, shift);

    printf("%s\n", message);
}
