#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtPosition(struct Node** head, int data, int pos);
void deleteAtPosition(struct Node** head, int pos);
void traverse(struct Node* head);
int countNodes(struct Node* head);
void searchElement(struct Node* head, int key);
void sortList(struct Node** head);
void reverseList(struct Node** head);

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, i, val, choice, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    do {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, val, pos);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 3:
                printf("The total number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                printf("The list is: ");
                traverse(head);
                break;
            case 5:
                printf("Enter element to be searched: ");
                scanf("%d", &val);
                searchElement(head, val);
                break;
            case 6:
                sortList(&head);
                printf("List sorted in ascending order.\n");
                break;
            case 7:
                reverseList(&head);
                printf("Reverse list: ");
                traverse(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at specific position
void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node at specific position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    if (pos == 1) {
        *head = temp->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}

// Count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Traverse the list
void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
        if (head != NULL) printf("->");
    }
    printf("\n");
}

// Search for an element
void searchElement(struct Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element found at node-%d\n", pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Element not found!\n");
}

// Sort list in ascending order
void sortList(struct Node** head) {
    struct Node* i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Reverse the list
void reverseList(struct Node** head) {
    struct Node* prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
