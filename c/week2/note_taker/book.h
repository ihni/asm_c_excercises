#ifndef NOTE_H
#define NOTE_H

#define MAX_PAGES         32
#define AUTHOR_LEN        64
#define PAGE_CONTENT_LEN  1024

struct Note {
    int number; // page number w/ regards to the book
    int total_chars;
    char content[PAGE_CONTENT_LEN];
    char author[AUTHOR_LEN];
};

struct Book {
    struct Note pages[MAX_PAGES];
    int current_page_num;
};

#endif
