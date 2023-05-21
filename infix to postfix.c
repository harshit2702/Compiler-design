#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 20

int top = -1;
char infix[MAX_SIZE], postfix[MAX_SIZE], stack[MAX_SIZE];

void push(char);
char pop();
int is_operator(char);
int precedence(char, int);
void infix_to_postfix();

int main() {
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_postfix();

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

void push(char symbol) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = symbol;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int is_operator(char symbol) {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') {
        return 1;
    }
    return 0;
}

int precedence(char symbol, int is_operator) {
    int precedence = 0;

    switch (symbol) {
        case '+':
        case '-':
            precedence = 1;
            break;
        case '*':
        case '/':
            precedence = 2;
            break;
        case '^':
            precedence = 3;
            break;
        default:
            if (is_operator) {
                printf("Invalid operator: %c\n", symbol);
                exit(1);
            }
            break;
    }

    return precedence;
}

void infix_to_postfix() {
    int i = 0, j = 0;
    char symbol;

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (is_operator(symbol)) {
            while (top != -1 && precedence(stack[top], 1) >= precedence(symbol, 0)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {
            printf("Invalid symbol: %c\n", symbol);
            exit(1);
        }

        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}