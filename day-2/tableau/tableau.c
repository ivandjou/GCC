#include <stdio.h>

int main() {
    // Déclaration et initialisation du tableau
    int nombres[5] = {10, 20, 30, 40, 50};

    // Affichage du tableau avec une boucle for
    for (int i = 0; i < 5; i++) {
        printf("nombres[%d] = %d\n", i, nombres[i]);
    }

    return 0;
}

