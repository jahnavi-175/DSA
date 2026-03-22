#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted\n", x);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node *temp = front;
    printf("Element deleted: %d\n", temp->data);
    front = front->next;

    if (front == NULL) rear = NULL;
    free(temp);
}

void traverse() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void isEmpty() {
    if (front == NULL)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. Traverse\n5. Exit\n");
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
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
