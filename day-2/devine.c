#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, proposition, essais = 0;

    // Initialiser le générateur aléatoire
    srand(time(NULL));
    secret = rand() % 100 + 1;

    printf("🎯 Devine le nombre entre 1 et 100 !\n");

    // Boucle de jeu
    do {
        printf("➡️ Entre ta proposition : ");
        scanf("%d", &proposition);
        essais++;

        if (proposition < secret) {
            printf("🔻 Trop petit !\n");
        } else if (proposition > secret) {
            printf("🔺 Trop grand !\n");
        } else {
            printf("🎉 Bravo ! Tu as trouvé en %d essais !\n", essais);
        }

    } while (proposition != secret);

    return 0;
}

