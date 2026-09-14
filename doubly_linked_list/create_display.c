#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, i;
    struct node *newNode, *temp;

    printf("Enter the number of nodes you want to create: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &newNode->value);
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("The doubly linked list is empty.\n");
        return;
    }

    printf("\nDoubly Linked List elements:\n");
    while (temp != NULL) {
        printf("%d ", temp->value);
        if (temp->next != NULL) {
            printf("<-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    create();
    display();
    return 0;
}
