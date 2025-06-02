#include <stdio.h>

int main() {
    // Déclare un tableau 2D de 2 lignes (étudiants) et 5 colonnes (notes)
    int grades[2][5];

    float average;
    int i, j;

    // Initialise les notes
    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    int students = 2;
    int subjects = 5;

    // Calcul de la moyenne par matière (colonne)
    for (j = 0; j < subjects; j++) {
        average = 0;
        for (i = 0; i < students; i++) {
            average += grades[i][j];
        }
        average /= students;

        printf("The average marks obtained in subject %d is: %.2f\n", j, average);
    }

    return 0;
}

