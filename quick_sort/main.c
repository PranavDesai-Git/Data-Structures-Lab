#include <stdio.h>

#define MAX_SIZE 1000
int arr[MAX_SIZE];
int n;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        quick_sort(low, pi - 1);
        quick_sort(pi + 1, high);
    }
}

int main() {
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n > MAX_SIZE)
        return 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
