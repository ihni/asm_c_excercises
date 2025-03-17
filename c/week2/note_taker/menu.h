#ifndef MENU_H
#define MENU_H

#include "book.h"

void print_operations(void);

void print_note(char *content, int total_chars, int number);

int take_note(struct Book *book, struct Note *note);    // creates a new note if space is
                                                        // is still available in the
                                                        // book struct

int view_note(struct Book *book, int page_number);      // works by grabbing the page number

#endif
