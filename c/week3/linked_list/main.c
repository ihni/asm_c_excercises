#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "llops.h"
#include "helpers.h"

int main(int argc, char *argv[]) {
    struct Node *list = NULL;
    int buffer;

    for (;;) {
        printf("1 : create node\n");
        printf("2 : search node\n");
        printf("3 : delete node\n");
        printf("4 : view list\n");
        printf("0 : exit program\n");

        printf("Enter options: ");
        scanf("%d", &buffer);
        
        switch (buffer) {
            case 1:
                create_node_helper(&list);
                break;
            case 2:
                search_node_helper(list);
                break;
            case 3:
                delete_node_helper(&list);
                break;
            case 4: print_list(list);
               break;
            default:
                printf("nothing\n");
                break;
        }
        printf("\n");
    }

    return 0;
}
