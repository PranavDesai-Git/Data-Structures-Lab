#include <stdio.h>

#define MAX_SIZE 1000
int arr[MAX_SIZE];
int n;

void insertion_sort() {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n > MAX_SIZE) return 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
