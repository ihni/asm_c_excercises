#include <stdio.h>
#include "menu.h"
#include "book.h"
#include "readline.h"

void print_operations(void) {
    printf("Here are the operations:\n");
    printf("------------------------------\n");
    printf("1 : Create a note\n");
    printf("2 : View a note by listing the page\n");
    printf("3 : Quit\n");
    printf("------------------------------\n\n");
}

void print_note(char *content, int total_chars, int number) {
    printf("------------------------------\n");
    printf("Contents:\n");
    printf("%s\n", content);
    printf("\nTotal characters: %4d\t\t\tPage Number %2d\n", 
           total_chars, number
    );
    printf("------------------------------\n");
}

int take_note(struct Book *book, struct Note *note) {
    if (book->current_page_num == MAX_PAGES)
        return 1;

    note->total_chars = readline(note->content, (int) sizeof(note->content));
    note->number = book->current_page_num + 1;
    book->pages[book->current_page_num++] = *note;
    

    return 0;
}

int view_note(struct Book *book, int page_number) {
    if (page_number > book->current_page_num) {
        return 1;
    }
    struct Note note = book->pages[page_number-1];
    print_note(note.content, note.total_chars, note.number);

    return 0;
}
