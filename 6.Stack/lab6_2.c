#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
    } else {
        struct Node* temp = top;
        printf("%d deleted from Stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
        printf("4. Traverse\n");
        printf("5. Exit\n");
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
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}
