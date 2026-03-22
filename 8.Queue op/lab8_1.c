#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return (front == -1);
}

void insertRight(int x) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
    printf("%d inserted at right\n", x);
}

void deleteLeft() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from left\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRight() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from right\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\nInput Restricted Deque Menu\n");
        printf("1. Insert at right\n2. Delete from left\n3. Delete from right\n4. Display\n5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                insertRight(val);
                break;
            case 2:
                deleteLeft();
                break;
            case 3:
                deleteRight();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
