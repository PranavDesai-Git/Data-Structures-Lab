#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void enqueue(int val) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->val = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = newnode;
}

int dequeue(int *val) {
    if (head == NULL)
        return -1;

    Node *p = head;
    *val = p->val;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    free(p);
    return 0;
}

void display() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node *p = head;
    printf("Queue: ");
    while (p != NULL) {
        printf("|%d| -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
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
            int x = 0;
            dequeue(&x);
            printf("Dequeue: %d\n", x);
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
