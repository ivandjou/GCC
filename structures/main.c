#include <stdio.h>

// Déclaration de la struct avec typedef
typedef struct {
    char* name;
    int age;
} person;

int main() {
    person john;

    /* testing code */
    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.\n", john.name, john.age);

    return 0;
}

