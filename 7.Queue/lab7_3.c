#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == (rear + 1) % size);
}

void enqueue(int queue[], int val) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", val);
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        queue[rear] = val;
    }
}

void dequeue(int queue[]) {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete\n");
    } else {
        printf("Element deleted\n");
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
}

void traverse(int queue[]) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("CQueue: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % size;
        }
        printf("\n");
    }
}

int main() {
    printf("Enter Queue size: ");
    scanf("%d", &size);
    int queue[size], choice, val;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                enqueue(queue, val);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Queue Empty: %s\n", isEmpty() ? "True" : "False");
                break;
            case 4:
                printf("Queue Full: %s\n", isFull() ? "True" : "False");
                break;
            case 5:
                traverse(queue);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}
