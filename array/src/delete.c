#include <stdlib.h>

int delete_at(int **arr, int *size, int i) {

  for (int j = i; j < *size - 1; j++) {
    (*arr)[j] = (*arr)[j + 1];
  }
  int *temp = realloc(*arr, (*size - 1) * sizeof(int));
  if (temp == NULL) {
    return 1;
  }
  *arr = temp;
  (*size)--;
  return 0;
}
