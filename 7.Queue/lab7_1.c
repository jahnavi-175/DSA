#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1) {
        printf("Queue is Full!\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = x;
        printf("%d inserted\n", x);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Element deleted: %d\n", queue[front]);
        front++;
    }
}

void traverse() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void isEmpty() {
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}

void isFull() {
    if (rear == SIZE - 1)
        printf("Queue is Full\n");
    else
        printf("Queue is Not Full\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                traverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
