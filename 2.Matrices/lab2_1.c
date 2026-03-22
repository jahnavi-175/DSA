#include <stdio.h>

#define MAX 100

void insert(int arr[], int *n, int elem, int pos) {
    if (*n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    else if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = elem;
    (*n)++;
    printf("Element inserted.\n");
}

void delete(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    else if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted.\n");
}

void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d.\n", i);
            return;
        }
    }
    printf("Element not found.\n");
}

void traverse(int arr[], int n) {
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n, choice, elem, pos, key;

    printf("Enter size n: ");
    scanf("%d", &n);

    printf("Enter Array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (100) {
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &elem);
                printf("Enter Position: ");
                scanf("%d", &pos);
                insert(arr, &n, elem, pos);
                break;
            case 2:
                printf("Enter Position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;
            case 4:
                traverse(arr, n);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}