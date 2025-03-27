#include "node.h"

#ifndef LLOPS_H
#define LLOPS_H

struct Node *create_node(const int value);

void add_to_beginning(struct Node **list, struct Node *node);
void add_to_end(struct Node **list, struct Node *node);

struct Node *search_node(struct Node *list, int target);

int delete_node(struct Node **list, int target);

void print_list(struct Node *list);

#endif
