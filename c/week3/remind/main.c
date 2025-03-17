#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_REMIND 50   // maximum number of reminders
#define MSG_LEN 60      // max length of a message

int main(int argc, char *argv[]) {
    char *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("--- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);

        if (day == 0)
            break;

        sprintf(day_str, "%2d", day);
        readline(msg_str, MSG_LEN);
        
        // search thru reminders to place in correct position
        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        }
        
        // move all the reminders i+1 up by 1
        for (j = num_remind; j > i; j--)
            reminders[j] = reminders[j-1];
        
        // making room for the day str, the message, and null char
        reminders[i] = malloc(2 + strlen(msg_str) + 1);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}
