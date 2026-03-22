#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX - 1);
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", val);
    } else {
        stack[++top] = val;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
    } else {
        printf("%d deleted from Stack\n", stack[top--]);
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Stack empty: %s\n", isEmpty() ? "True" : "False");
                break;
            case 4:
                printf("Stack full: %s\n", isFull() ? "True" : "False");
                break;
            case 5:
                traverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}
