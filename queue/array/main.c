#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int top = 0;
int bottom = 0;

int enqueue(int val) {
    if (bottom >= SIZE) {
        printf("Error: Queue Overflow!\n");
        return 1;
    }
    queue[bottom++] = val;
    return 0;
}

int dequeue() {
    if (top == bottom) {
        printf("Error: Queue Underflow!\n");
        return 1;
    }
    printf("Dequeued: %d\n", queue[top++]);

    if (top == bottom) {
        top = 0;
        bottom = 0;
    }
    return 0;
}

void display() {
    if (top == bottom) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = top; i < bottom; ++i) {
        printf("|%d| ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice = 0, value = 0;

    printf("Queue Operations:\n"
           "1. Enqueue\n"
           "2. Dequeue\n"
           "3. Display\n"
           "4. Exit\n");

    while (1) {
        printf("\n>> ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
        case 1:
            printf("Enter value > ");
            scanf("%d", &value);
            enqueue(value);
            display();
            break;
        case 2:
            dequeue();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
