#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insertAtBegin();
void insertAtEnd();
void insertAtPOS();
void deleteBegin();
void deleteAtEnd();
void deleteAtPOS();

struct node {
    int value;
    struct node *next;
};

struct node *Head = NULL, *newnode = NULL, *temp = NULL, *p;
int x;

int main() {
    int ch;
    printf("\n------------");
    printf("\nCircular Single Linked List");
    printf("\n------------");

    printf("\n1. Create");
    printf("\n2. Display");
    printf("\n3. Exit");
    printf("\n4. Insert At Begin");
    printf("\n5. Insert At End");
    printf("\n6. Insert At Position");
    printf("\n7. Delete At Beginning");
    printf("\n8. Delete At End");
    printf("\n9. Delete At Position\n");

    while (1) {
        printf("\n\n-->Enter Your Choice:");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            create();
            display();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        case 4:
            insertAtBegin();
            display();
            break;
        case 5:
            insertAtEnd();
            display();
            break;
        case 6:
            insertAtPOS();
            display();
            break;
        case 7:
            deleteBegin();
            display();
            break;
        case 8:
            deleteAtEnd();
            display();
            break;
        case 9:
            deleteAtPOS();
            display();
            break;
        default:
            printf("enter valid choice");
        }
    }
}

void create() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value:");
    scanf("%d", &x);
    newnode->value = x;
    newnode->next = NULL;
    if (Head == NULL) {
        Head = newnode;
        Head->next = Head;
    } else {
        p = Head;
        while (p->next != Head)
            p = p->next;
        p->next = newnode;
        newnode->next = Head;
    }
}

void display() {
    if (Head == NULL) {
        printf("\nList is empty!");
        return;
    }
    p = Head;
    printf("\nList: ");
    do {
        printf("%d->", p->value);
        p = p->next;
    } while (p != Head);
    printf("%d", Head->value);
}

void insertAtBegin() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Element:");
    scanf("%d", &x);
    newnode->value = x;
    newnode->next = NULL;
    if (Head == NULL) {
        Head = newnode;
        Head->next = Head;
    } else {
        p = Head;
        while (p->next != Head) {
            p = p->next;
        }
        newnode->next = Head;
        p->next = newnode;
        Head = newnode;
    }
}

void insertAtEnd() {
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value : ");
    scanf("%d", &x);
    newnode->value = x;
    newnode->next = NULL;

    if (Head == NULL) {
        Head = newnode;
        Head->next = Head;
    } else {
        p = Head;
        while (p->next != Head) {
            p = p->next;
        }
        p->next = newnode;
        newnode->next = Head;
    }
}

void insertAtPOS() {
    int pos, i;
    printf("\nEnter the position : ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertAtBegin();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value : ");
    scanf("%d", &x);
    newnode->value = x;
    newnode->next = NULL;

    p = Head;
    for (i = 1; i < pos - 1 && p->next != Head; i++) {
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
}

void deleteBegin() {
    if (Head == NULL)
        printf("empty list!delete not possible\n");
    else if (Head->next == Head) {
        free(Head);
        Head = NULL;
        printf("\nThe Element deleted Successfully ");
    } else {
        temp = Head;
        p = Head;
        while (p->next != Head) {
            p = p->next;
        }

        Head = Head->next;
        p->next = Head;
        temp->next = NULL;
        free(temp);
        printf("\nThe Element deleted Successfully ");
    }
}

void deleteAtEnd() {
    if (Head == NULL)
        printf("empty list!delete not possible\n");
    else if (Head->next == Head) {
        free(Head);
        Head = NULL;
        printf("element deleted successfully");
    } else {
        p = Head;
        while (p->next->next != Head) {
            p = p->next;
        }
        temp = p->next;
        p->next = Head;
        free(temp);
        printf("element deleted successfully");
    }
}

void deleteAtPOS() {
    int pos, i;
    if (Head == NULL) {
        printf("empty list!delete not possible\n");
        return;
    }
    printf("\nEnter the Position of the element you would like to delete:");
    scanf("%d", &pos);
    if (pos == 1) {
        deleteBegin();
        return;
    }
    p = Head;
    for (i = 1; i < pos - 1 && p->next != Head; i++)
        p = p->next;
    if (p->next == Head) {
        printf("\nInvalid Position!");
        return;
    }
    temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    free(temp);
    printf("\nExecuted-->Node is deleted!!");
}
