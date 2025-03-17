// to make use of dynamic memory allocation use this:
#include <stdlib.h>

//->
// malloc - allocates a block of memory but doesn't initialize it
// calloc - allocates a block of memory and clears it
// realloc - resizes a previously allocated block of memory
//
// malloc is most used, more effienct than calloc, since it doesnt
// have to clear memory block that it allocates
//

// when we ask for a block of memory, it doesnt know the data type
// we're planning to store in the block, it can't return a pointer to
// an ordinary type such as int or char,  instead, the function returns
// a value of type:
//          
//          void *
//
//  A void * value is a "generic" pointer, essentially, just a memory address
//

// NULL POINTERS
// there's a possiblity that when a memory allocator is called, that it won't be
// be able to locate a block of memory large enough to satisfy our request.
// If so, the function will return a null pointer
//
// -> a pointer to nothing
//
// a special value that can be distinguished from all valid pointers
//
// after we've stored the function's return value in a pointer value,
// WE MUST TEST TO SEE IF IT"S A NULL POINTER
//
// it's our responsibility to test the return value & take appropriate action
// if it's a null pointer. It can crash or behave unpredictable if we accessed
// memory through a null pointer
//

// null pointer is defined by a macro named
//
//      NULL
//
//  which can be founed in six headers:
//  <locale.h>, <stddef.h>
//  <stdio.h>,  <stdlib.h>
//  <string.h>, <time.h>
//  <wchar.h> also defines but only in post C99
// 

// any program that uses memory allocators already needs to use stdlib.h so no worries
//

int *p = malloc(100000);
if (p == NULL) {
    /* allocation failed; take appropriate action */
}

//
// we can use malloc for allocating a block size of bytes which returns a pointer to it
// size has size_t, an unsigned int type defined in the C library
// the prototype of malloc
//
void *malloc(size_t size);

int n = 5; // however many characters we use for creating a string
char *p;
p = malloc(n+1); // n + 1 to account for the null char = '\0'
// the generic pointer will be converted when the assignment is performend
// no cast is neccessary

// however we can cast malloc's return value
char *p = (char *) malloc(n + 1);

// concat function that will actually concat both chars unlike the standard c function
// which will truncate if it doesn't fit
//
#include <string.h>
char *concat(const char *s1, const char *s2);

char *concat(const char *s1, const char *s2) {
    char *result;

    result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result,s1);
    strcat(result, s2);

    return result;
}

// sometimes we need to recover from a memory allocation failure and continue running
// instead of exiting the program

char *str = concat("abc", "def");

// use dynamically allocated storage with care, when the string that concat returns is no longer
// needed, we need to call the free function to release that space the string ocupies,
// if not, program will eventually run out of space;
