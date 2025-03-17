#include <stdio.h>
#include <string.h>

// structure tag
struct Person {
    int number;
    char name[256];
};

// structure variable
struct {
    int number;
    char name[256];
} person_one;

// typedef structure
typedef struct {
    int number;
    char name[256];
} TypePerson;

// combining typedef with struct tags
typedef struct ExamplePerson {
    int ex;
    char ex[256];
} ExamplePerson;

//
typedef struct StructPerson;
struct StructPerson {
    int ex;
    char ex[256];
};

//----------------------------------------------------

struct Person create_person(char *name, int number);

struct Person create_person(char *name, int number) {
    struct Person person;
    person.number = number;
    strcpy(person.name, name);
    return person;
}

TypePerson create_type_person(char *name, int number) {
    TypePerson person;
    person.number = number;
    strcpy(person.name, name);
    return person;
}

int main(void) {
    person_one.number = 1;
    strcpy(person_one.name, "Johnson");

    struct Person person_two;
    person_two.number = 2;
    strcpy(person_two.name, "Jeffreson");

    struct Person person_three = create_person("Jack", 3);
    TypePerson person_four = create_type_person("James", 4);

    printf("%d: %s\n", person_one.number, person_one.name);
    printf("%d: %s\n", person_two.number, person_two.name);
    printf("%d: %s\n", person_three.number, person_three.name);
    printf("%d: %s\n", person_four.number, person_four.name);

    
    return 0;
}
