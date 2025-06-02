#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} node_t;

void insert(node_t **tree, int val);
void printDFS(node_t *current);

int main() {
  node_t *test_list = NULL;  // arbre vide au départ

  insert(&test_list, 5);
  insert(&test_list, 8);
  insert(&test_list, 4);
  insert(&test_list, 3);

  printDFS(test_list);
  printf("\n");

  return 0;
}

// insert avec un double pointeur
void insert(node_t **tree, int val) {
  if (*tree == NULL) {
    *tree = malloc(sizeof(node_t));
    (*tree)->val = val;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    return;
  }

  if (val < (*tree)->val) {
    insert(&(*tree)->left, val);
  } else {
    insert(&(*tree)->right, val);
  }
}

// DFS in-order : gauche - racine - droite
void printDFS(node_t *current) {
  if (current == NULL) return;

  printDFS(current->left);
  printf("%d ", current->val);
  printDFS(current->right);
}

