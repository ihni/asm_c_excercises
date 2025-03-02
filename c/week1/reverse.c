// takes in command line args and 
// displays them in reverse
//
// example:
//      ./reverse arg1 arg2 arg3
//
//  output:
//      arg3 arg2 arg1

#include <stdio.h>

#define MAX_ARGC 256

int main(int argc, char **argv) {
    // buffer stores the reverse args
    char *buffer[MAX_ARGC];
    char **ptr = buffer;
    
    if (argc == 1) {
        printf("no arguments were listed...\n");
        return 0;
    }
    
    for (char **p = argv + argc - 1; p > argv;p--) {
        *ptr++ = *p;
    }

    for (char **p = buffer; p < buffer + argc - 1;)
        printf("%s ", *p++);
    printf("\n");

    return 0;
}
