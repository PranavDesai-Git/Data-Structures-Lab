#include <stdio.h>
#include <stdlib.h>

void print_int_arr(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; ++i) {
    if (i == size - 1) {
      printf("%d", arr[i]);
      continue;
    }
    printf("%d,", arr[i]);
  }
  printf("]\n");
}

int accept_int_array(int **arr, int *size) {
  int input_size;
  printf("Size of the Array to Create:");
  scanf("%d", &input_size);

  int *temp = realloc(*arr, input_size * sizeof(int));

  if (temp != NULL) {
    *arr = temp;
    *size = input_size;
    for (int i = 0; i < *size; ++i) {
      printf("arr[%d]:", i);
      scanf("%d", &(*arr)[i]);
    }
  } else
    return 1;
  return 0;
}
