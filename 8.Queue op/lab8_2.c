#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

void enqueue(int val, int pri) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->priority = pri;
    newNode->next = NULL;

    if (front == NULL || pri < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= pri) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted with priority %d\n", val, pri);
}

void dequeue() {
    if (front == NULL) {
        printf("Priority Queue is Empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted: %d with priority %d\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Priority Queue is Empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Priority Queue:\n");
    while (temp != NULL) {
        printf("%d (priority %d)\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int choice, val, pri;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                printf("Enter priority: ");
                scanf("%d", &pri);
                enqueue(val, pri);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
