#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row, col, value;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int r, int c, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = r;
    newNode->col = c;
    newNode->value = v;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(int rows, int cols) {
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d\n", rows, cols);
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int rows, cols, val;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of sparse matrix: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &val);
            if (val != 0)
                insert(i, j, val);
        }
    }
    display(rows, cols);
    return 0;
}
