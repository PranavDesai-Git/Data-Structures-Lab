void bubble_sort(int *arr, int size) {
  int sorted = 0;
  do {
    sorted = 0;
    for (int i = 1; i < size; ++i) {
      if (arr[i - 1] > arr[i]) {
        int temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
        sorted = 1;
      }
    }
  } while (sorted != 0);
}
