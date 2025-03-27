#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "llops.h"

struct Node *create_node(const int value) {
    struct Node *node;
    node = malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Malloc returned a null pointer.\n");
        exit(EXIT_FAILURE);
    }
    
    node->value = value;
    return node;
}

// 
// Adding
//

void add_to_beginning(struct Node **list, struct Node *node) {
    if (*list == NULL) {
        *list = node;
        node->next = NULL;
    } else {
        node->next = *list;
        *list = node;
    }
}

void add_to_end(struct Node **list, struct Node *node) {
    if (*list == NULL) {
        *list = node;
        node->next = NULL;
    } else {
        struct Node *current = *list;
        
        while (current->next)
            current = current->next;

        current->next = node;
    }
}

//
// Searching
//

struct Node *search_node(struct Node *list, int target) {
    for (; list; list = list->next) {
        if (list->value == target) 
            return list;
    }

    return NULL;
}

// 
// Deleting
//

int delete_node(struct Node **list, int target) {
    struct Node *current, *previous;
    
    for (current = *list, previous = NULL;
         current != NULL && current->value != target;
         previous = current, current = current->next) {}

    if (current == NULL) {         // if target doesn't exist
        return 0;
    } else if (previous == NULL) { // if target is the first
        *list = (*list)->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return 1;
}

//
// Miscellaenous
//

void print_list(struct Node *list) {
    for (; list; list = list->next)
        printf("%d -> ", list->value);
    printf("NULL\n");
}
