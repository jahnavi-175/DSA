#include <stdio.h>

void selectionSortAsc(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void selectionSortDesc(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int max = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[max])
                max = j;
        }
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, arr[100], temp[100];

    printf("Enter no.of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        temp[i] = arr[i];
    }

    selectionSortAsc(arr, n);
    printf("Ascending order: ");
    printArray(arr, n);

    selectionSortDesc(temp, n);
    printf("Descending order: ");
    printArray(temp, n);

    return 0;
}