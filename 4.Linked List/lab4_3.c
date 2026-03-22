#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff;
    int power;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int coeff, int power);
void insertTerm(struct Node** head, int coeff, int power);
void createPolynomial(struct Node** head);
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2);
void display(struct Node* head);

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    printf("Polynomial-1:\n");
    createPolynomial(&poly1);

    printf("Polynomial-2:\n");
    createPolynomial(&poly2);

    sum = addPolynomials(poly1, poly2);

    printf("\nSum: ");
    display(sum);

    return 0;
}

// Create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Insert term into polynomial (at end)
void insertTerm(struct Node** head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Create polynomial by user input
void createPolynomial(struct Node** head) {
    int maxPow, coeff;
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPow);

    for (int i = maxPow; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {
            insertTerm(head, coeff, i);
        }
    }
}

// Add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertTerm(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else if (poly1->power < poly2->power) {
            insertTerm(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
        else { // powers equal
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Copy remaining terms
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

// Display polynomial
void display(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}
