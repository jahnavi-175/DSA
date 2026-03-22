#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int isOperator(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

void infixToPostfix(char* exp) {
    char result[MAX];
    int k = 0;
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalnum(c)) {
            result[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                result[k++] = pop();
            }
            pop();
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c) && c!='^') {
                result[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        result[k++] = pop();
    }
    result[k] = '\0';
    printf("Postfix: %s\n", result);
}

int main() {
    char exp[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}
