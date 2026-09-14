#include "arrayio.h"
#include "bubblesort.h"
#include "delete.h"
#include "insert.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, v;
  int size = 10;
  int *arr = malloc(size * sizeof(int));
  accept_int_array(&arr, &size);
  print_int_arr(arr, size);
  printf("insert value into array at an index. spacify in\n> index,value\n> ");
  scanf("%d,%d", &i, &v);
  insert_at(&arr, &size, i, v);
  print_int_arr(arr, size);
  printf("enter where we have to insert after in index,value\n> ");
  scanf("%d,%d", &i, &v);
  insert_after(&arr, &size, i, v);
  print_int_arr(arr, size);
  printf("enter the index you want to delete\n> ");
  scanf("%d", &i);
  delete_at(&arr, &size, i);
  print_int_arr(arr, size);
  printf("Sorted array:");
  bubble_sort(arr, size);
  print_int_arr(arr, size);
  free(arr);
  return 0;
}
