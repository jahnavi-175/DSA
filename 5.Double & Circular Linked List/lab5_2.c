#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int n) {
    struct Node* temp, *newNode;
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter info of node%d: ", i+1);
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        if (head == NULL) {
            head = newNode;
            head->next = head;
            temp = head;
        } else {
            newNode->next = head;
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void display() {
    struct Node* temp = head;
    if (head == NULL) return;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("Clinkedlist: ");
    display();
    return 0;
}
