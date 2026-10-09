#include <stdio.h>

#define MAX_SIZE 1000
int arr[MAX_SIZE];
int n;

int binary_search(int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int target;
    printf("Enter the number of elements (must be sorted for binary search): ");
    if (scanf("%d", &n) != 1 || n > MAX_SIZE) return 1;

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    if (scanf("%d", &target) != 1) return 1;

    int result = binary_search(target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
