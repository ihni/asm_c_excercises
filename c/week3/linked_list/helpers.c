#include <stdio.h>
#include <stdlib.h>
#include "llops.h"
#include "node.h"
#include "helpers.h"

void create_node_helper(struct Node **list) {
    struct Node *node;
    int buffer;

    printf("Enter a value: ");
    scanf("%d", &buffer);

    node = create_node(buffer);

    printf("1 : add to beginning\n");
    printf("2 : add to end\n");
    printf("Choose option of insertion: ");
    scanf("%d", &buffer);

    switch (buffer) {
        case 1:
            add_to_beginning(list, node);
            break;
        case 2:
            add_to_end(list, node);
            break;
        default:
            printf("[ERROR] Error with user input\n");
            printf("[ERROR] Cleaning up heap\n");
            free(node);
            break;
    }
}

void search_node_helper(struct Node *list) {
    int target;
    
    printf("Enter a target value: ");
    scanf("%d", &target);

    struct Node *node = search_node(list, target);

    if (node == NULL) {
        printf("[RESULT] Node %d not found.\n", target);
    } else {
        printf("[RESULT] Node %d found!\n", node->value);
    }
}

void delete_node_helper(struct Node **list) {
    int target, result;

    print_list(*list);
    printf("Enter a node value to be deleted: ");
    scanf("%d", &target);
   
    result = delete_node(list, target);
    if (result) {
        printf("[RESULT] Node %d has been deleted.\n", target);
    } else {
        printf("[RESULT] Node %d does not exist, cannot delete.\n", target);
    }
}

