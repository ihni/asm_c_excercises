#include <stdio.h>

struct S {
    char a;
    int b;
};

struct S1 {
    int b;
    char a;
};

int main(int argc, char **argv) {
    struct S struct_1;
    struct S1 struct_2;
    
    size_t s1_size = sizeof(struct_1);
    size_t s2_size = sizeof(struct_2);

    printf("Struct 1 size: %zu\n", s1_size);
    printf("Struct 2 size: %zu\n", s2_size);

    return 0;
}
