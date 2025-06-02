#include <stdio.h>

int main() {
    int n = 10;

    // Déclare un pointeur vers n
    int* pointer_to_n = &n;

    // Utilise le pointeur pour modifier n
    *pointer_to_n = 11;

    /* testing code */
    if (pointer_to_n != &n) return 1;
    if (*pointer_to_n != 11) return 1;

    printf("Done!\n");
    return 0;
}

