#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

int findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int height(struct node* root) {
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int countLeafNodes(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct node* root = NULL;
    int n, value, choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    do {
        printf("\nMAIN MENU\n1. Insert\n2. Largest\n3. Smallest\n4. Height\n5. Count leaf nodes\n6. Exit\nEnter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert in BST: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Largest element in BST = %d\n", findMax(root));
                break;
            case 3:
                printf("Smallest element in BST = %d\n", findMin(root));
                break;
            case 4:
                printf("Height of BST = %d\n", height(root));
                break;
            case 5:
                printf("Number of leaf nodes = %d\n", countLeafNodes(root));
                break;
            case 6: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
