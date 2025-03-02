// a program that prints a one-month list of daily reminders
// example:
//
// Enter day and reminder: 24 Susan's birthday
//                         ^        ^
//                      both 24 and susan's birthday
//                      will be printed seperately
//

#include <stdio.h>
#include <string.h>

#define MAX_REMINDERS   32 
#define REMINDER_LEN    32 

int read_line(char *s, int n);

int read_line(char *s, int n) {
    int count = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        if (count < n) {
            *s++ = ch;
            count++;
        }
    }
    *s = '\0';
    return count;
}

int main(void) {
    // total number of pointers is 255
    char reminders[MAX_REMINDERS][REMINDER_LEN+3];
    int num_of_reminders = 0;
    for (;;) {
        char day_str[3];
        int day, i, j;
        char reminder[REMINDER_LEN];
        if (num_of_reminders == MAX_REMINDERS) {
            printf("--- No space left ---\n");
            break;
        }
        // day and reminder are taken seperately
        // day will be taken using scanf
        // reminder will be taken using read_line()
        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0) break; // exit num for loop is 0
        sprintf(day_str, "%2d", day);
        read_line(reminder, REMINDER_LEN); // assuming i'm able to get the reminder
                                           // seperately

        // sorting through the reminders such that the days are in order
        for (i = 0; i < num_of_reminders; i++) {
            if (strcmp(day_str, reminders[i]) < 0) break;
        }
        // once the correct position is found
        // move all the elements up by one by copying low to high
        for (j = num_of_reminders; j > i; j--) {
            strcpy(reminders[j], reminders[j-1]);
        }
        
        // putting the day as the first char in the reminders
        // then appending the actual reminder to it
        strcpy(reminders[i], day_str);
        strcat(reminders[i], reminder);
        num_of_reminders++;
    }
    // Displaying all reminders
    printf("\nDay Reminder\n");
    for (int i = 0; i < num_of_reminders; i++) {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}
