#include <stdbool.h>
#include <stdio.h>
#define SIZE 64

typedef struct {
    int data[SIZE];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }

bool isFull(const Stack *s) { return (s->top == SIZE - 1); }
bool isEmpty(const Stack *s) { return (s->top == -1); }

void printStack(const Stack *s) {
    if (isEmpty(s)) {
        printf("EMPTY STACK\n");
        return;
    }
    for (int i = s->top; i >= 0; --i) {
        printf("[%d] %d\n", i, s->data[i]);
    }
}

int push(Stack *s, int v) {
    if (isFull(s))
        return 1;
    s->data[++(s->top)] = v;
    return 0;
}

int pop(Stack *s) {
    if (isEmpty(s))
        return -1;
    int r = s->data[s->top];
    s->top--;
    return r;
}

int main() {
    Stack s;
    initStack(&s);
    while (true) {
        int choice = 0;
        int v = 0;
        printf("--------------\n"
               "Choose option:\n"
               "1. Display\n"
               "2. Push\n"
               "3. Pop\n"
               "4. Exit\n"
               "--------------\n\n"
               "> ");

        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printStack(&s);
            break;
        case 2:
            printf("Value> ");
            scanf("%d", &v);
            push(&s, v);
            printStack(&s);
            break;
        case 3:
            v = pop(&s);
            printf("popped element: %d\n", v);
            printStack(&s);
            break;
        case 4:
            return 0;
        default:
            continue;
        }
        printf("\n\n\n\n\n");
    }
}
