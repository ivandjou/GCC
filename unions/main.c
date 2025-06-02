#include <stdio.h>

// Déclaration de l’union : 6 entiers (6 x 4 = 24 octets) ou 24 caractères
union int_char_union {
    int ints[6];
    char chars[24];
};

int main() {
    // Initialisation des 6 entiers, ce qui remplit aussi les 24 chars
    union int_char_union intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};

    /* testing code */
    printf("[");
    for (int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars);

    return 0;
}

