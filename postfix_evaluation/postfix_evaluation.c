// Program to evaluate the given postfix expression

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int character);
int postfix_evaluation();
int pop();
int isEmpty();

int top;
int stack[50];
char postfix_expression[50];

int main() {
    int evaluated_value;
    top = -1;

    printf("\nEnter an expression in postfix format: ");
    scanf("%s", postfix_expression);

    printf("\nExpression in postfix format: %s\n", postfix_expression);

    evaluated_value = postfix_evaluation();
    printf("\nEvaluation of postfix expression: %d\n", evaluated_value);

    return 0;
}

int postfix_evaluation() {
    int x, y, temp, value;
    int count;

    for (count = 0; count < strlen(postfix_expression); count++) {
        if (postfix_expression[count] <= '9' &&
            postfix_expression[count] >= '0') {
            push(postfix_expression[count] - '0');
        } else {
            x = pop();
            y = pop();
            switch (postfix_expression[count]) {
            case '+':
                temp = y + x;
                break;
            case '-':
                temp = y - x;
                break;
            case '*':
                temp = y * x;
                break;
            case '/':
                temp = y / x;
                break;
            case '%':
                temp = y % x;
                break;
            case '^':
                temp = pow(y, x);
                break;
            default:
                printf("Invalid operator\n");
            }
            push(temp);
        }
    }

    value = pop();
    return value;
}

void push(int character) {
    if (top > 50) {
        printf("Stack overflow\n");
        exit(1);
    }
    top = top + 1;
    stack[top] = character;
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
