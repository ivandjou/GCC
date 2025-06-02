#include <stdio.h>

int main() {
    int intarray[5] = {10, 20, 30, 40, 50};
    int *pointer = &intarray[2];  // pointe vers intarray[2] = 30

    // Tableau de 3 pointeurs
    int *parray[3];

    // Copier les 3 dernières adresses de intarray dans parray via pointer
    int i;
    for (i = 0; i < 3; i++) {
        parray[i] = &pointer[i];
    }

    // Test code
    for (i = 0; i < 3; i++) {
        if (parray[i] == &pointer[i]) {
            printf("Matched!\n");
        } else {
            printf("Fail\n");
        }
    }

    return 0;
}

