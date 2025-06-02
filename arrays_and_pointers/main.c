#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int **pnumbers; // Déclaration du pointeur vers un tableau de pointeurs

    // Allouer de la mémoire pour 3 lignes
    pnumbers = (int **)malloc(3 * sizeof(int *));

    // Allouer la mémoire pour chaque ligne, selon le nombre d’éléments
    pnumbers[0] = (int *)malloc(1 * sizeof(int));
    pnumbers[1] = (int *)malloc(2 * sizeof(int));
    pnumbers[2] = (int *)malloc(3 * sizeof(int));

    // Initialisation des valeurs
    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    // Affichage du triangle
    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    // Libération mémoire de chaque ligne
    for (i = 0; i < 3; i++) {
        free(pnumbers[i]);
    }

    // Libération du tableau de pointeurs
    free(pnumbers);

    return 0;
}

