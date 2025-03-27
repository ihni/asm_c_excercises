#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int value;          // data stored in the node
    struct Node *next;  // pointer to the next node
} Node;

#endif
