
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
        newNode = malloc(sizeof(struct node));
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

void insertBegin() {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value to insert at beginning: ");
    scanf("%d", &newNode->value);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertEnd() {
    struct node *newNode = malloc(sizeof(struct node));
    struct node *temp;
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter value to insert at end: ");
    scanf("%d", &newNode->value);
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
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

void insertAtPos() {
    int pos, i;
    struct node *newNode, *temp;

    printf("Enter the position to insert: ");
    if (scanf("%d", &pos) != 1 || pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertBegin();
        return;
    }

    newNode = malloc(sizeof(struct node));

    printf("Enter value to insert: ");
    scanf("%d", &newNode->value);

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void deleteBegin() {
    struct node *temp;
    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void deleteEnd() {
    struct node *temp;
    temp = head;
    if (head->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    free(temp);
}

void deletePos() {
    int pos, i;
    struct node *temp;
    printf("Enter the position to delete: ");
    if (scanf("%d", &pos) != 1 || pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        deleteBegin();
        return;
    }
    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

int main() {
    create();
    display();

    insertBegin();
    display();

    insertEnd();
    display();

    insertAtPos();
    display();

    printf("\n--- Testing Deletions ---\n");
    deleteBegin();
    display();

    deleteEnd();
    display();

    deletePos();
    display();

    return 0;
}
