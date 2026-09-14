// Program to convert infix expression to postfix by using stacks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expression_conversion();
int check_space_tabs(char character);
void push(int character);
int pop();
int priority(char character);
int isEmpty();
int top;
int stack[50];
char infix_expression[50], postfix_expression[50];

int main() {
    top = -1;
    printf("\nEnter an expression in infix format: ");
    scanf("%s", infix_expression);

    expression_conversion();

    printf("\nExpression in postfix format: %s\n", postfix_expression);
    return 0;
}

void expression_conversion() {
    int count, temp = 0;
    char next;
    char character;

    for (count = 0; count < strlen(infix_expression); count++) {
        character = infix_expression[count];
        if (!check_space_tabs(character)) {
            switch (character) {
            case '(':
                push(character);
                break;
            case ')':
                while ((next = pop()) != '(') {
                    postfix_expression[temp++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!isEmpty() &&
                       priority(stack[top]) >= priority(character)) {
                    postfix_expression[temp++] = pop();
                }
                push(character);
                break;
            default:
                postfix_expression[temp++] = character;
            }
        }
    }

    while (!isEmpty()) {
        postfix_expression[temp++] = pop();
    }
    postfix_expression[temp] = '\0';
}

int priority(char character) {
    switch (character) {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void push(int character) {
    if (top > 50) {
        printf("Stack overflow\n");
        exit(1);
    }
    top = top + 1;
    stack[top] = character;
}

int check_space_tabs(char character) {
    if (character == ' ' || character == '\t') {
        return 1;
    } else {
        return 0;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}
