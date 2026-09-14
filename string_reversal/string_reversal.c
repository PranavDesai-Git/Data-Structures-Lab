#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }
    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    if (fgets(str, MAX, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0'; // Remove trailing newline
        printf("Original string: %s\n", str);
        reverseString(str);
        printf("Reversed string: %s\n", str);
    }
    return 0;
}
