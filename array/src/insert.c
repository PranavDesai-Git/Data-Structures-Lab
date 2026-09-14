#include <stdlib.h>

int insert_at(int **arr, int *size, int i, int v) {
  int *temp = realloc(*arr, (*size + 1) * sizeof(int));
  if (temp == NULL) {
    return 1;
  }
  *arr = temp;
  for (int j = *size; j > i; --j) {
    (*arr)[j] = (*arr)[j - 1];
  }
  (*arr)[i] = v;
  (*size)++;
  return 0;
}

int insert_after(int **arr, int *size, int i, int v) {
  int *temp = realloc(*arr, (*size + 1) * sizeof(int));
  if (temp == NULL) {
    return 1;
  }
  *arr = temp;
  for (int j = *size; j > i; --j) {
    (*arr)[j] = (*arr)[j - 1];
  }
  (*arr)[i + 1] = v;
  (*size)++;
  return 0;
}

int insert_before(int **arr, int *size, int i, int v) {
  int *temp = realloc(*arr, (*size + 1) * sizeof(int));
  if (temp == NULL) {
    return 1;
  }
  *arr = temp;
  for (int j = *size; j >= i; --j) {
    (*arr)[j] = (*arr)[j - 1];
  }
  (*arr)[i - 1] = v;
  (*size)++;
  return 0;
}
