#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} point;

int main() {
  point *mypoint = NULL;

  // Allocation dynamique d'une structure point
  mypoint = (point *)malloc(sizeof(point));

  // Vérifie si l'allocation a réussi
  if (mypoint == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    return 1;
  }

  mypoint->x = 10;
  mypoint->y = 5;

  printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

  // Libération de la mémoire
  free(mypoint);

  return 0;
}

