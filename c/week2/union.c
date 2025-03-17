#include <stdio.h>

// i and d are stored in the same address
union {
    int i;
    double d;
} u;

// only one member of the union can have an initial
// value, it doesn't have to be the first one however
union {
    int i;
    double d;
} uni = {0};

// like this: 
union {
    int i;
    double d;
} uni_v2 = {.d = 10.0};

// example of use case
// take a look at this
struct Item {
    int stoack_number;
    double price;
    int item_type;
    char title[0xFF];
    char author[0xFF];
    int num_pages;
    char design[0xFF];
    int colors;
    int sizes;
};
// only part of the information in the structure is common to all items of a catalogue
// e.g, if it's a book, no need for design, colors, & sizes
// putting a union here can reduce the space required by the struct
struct Item {
    int stock_number;
    double price;
    int item_type;
    union {
        struct {
            char title[0xff];
            char author[0xff];
            int num_pages;
        } book;
        struct {
            char design[0xff];
        } mug;
        struct {
            char design[0xff];
            int colors;
            int sizes;
        } shirt;
    } item;
};
// union is named item
// structs are members of union

// we can use unions to create data structs that contain a mixture of data of different
// types
typedef union {
    int i;
    double d;
} Number;
Number number_array[1000];
number_array[0].i = 5;
number_array[1].d = 8.395;
