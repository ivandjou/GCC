#include <stdio.h>

void guessNumber(int guess) {
    int secret = 555; // le nombre à deviner

    if (guess < secret) {
        printf("Your guess %d is too low.\n", guess);
    } else if (guess > secret) {
        printf("Your guess %d is too high.\n", guess);
    } else {
        printf("Congratulations! You guessed the number: %d\n", guess);
    }
}

int main() {
    guessNumber(500); // trop bas
    guessNumber(600); // trop haut
    guessNumber(555); // exact
    return 0;
}

