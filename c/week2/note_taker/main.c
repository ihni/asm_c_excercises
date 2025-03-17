#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "book.h"
#include "menu.h"

int main(int argc, char *argv[]) {
    printf("Welcome,\n\n");
    struct Book book = { .current_page_num = 0 };
    int opt;

    for (;;) {
        print_operations();
        printf("Enter operation: ");
        scanf("%d", &opt);
        // getchar();
        printf("\n");
        
        switch (opt) {
            case 1:  {
                     struct Note note;
                     printf("Enter a note: ");
                     take_note(&book, &note);
                     printf("Finished writing page: %d\n", book.current_page_num);
                     printf("\n");
                     break;
                     }
            case 2:  printf("Enter the page number: ");
                     scanf("%d", &opt);
                     if (view_note(&book, opt))
                        printf("\n[ERROR], invalid page number, try again...\n\n");
                     break;
            case 3:  printf("Exiting...\n");
                     exit(0);
                     break;
            default: printf("\n[ERROR], invalid input, try again...\n\n");
        }
    }


    return 0;
}
