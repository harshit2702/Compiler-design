#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

char stack[MAX_SIZE];
int top = -1;

void reverse_string(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


void push(char ch) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    char ch = stack[top];
    top--;
    return ch;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    reverse_string(infix);
    int len = strlen(infix);
    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                prefix[strlen(prefix)] = pop();
            }
            push(ch);
        } else if (ch == ')') {
            push(ch);
        } else if (ch == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[strlen(prefix)] = pop();
            }
            pop();
        } else {
            prefix[strlen(prefix)] = ch;
        }
    }
    while (top != -1) {
        prefix[strlen(prefix)] = pop();
    }
    reverse_string(prefix);
}

int main() {
    char infix[20], prefix[20];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}