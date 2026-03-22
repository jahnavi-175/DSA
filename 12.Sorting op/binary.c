#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return 1;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int main() {
    int n, arr[100], key;

    printf("Enter no.of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to be searched: ");
    scanf("%d", &key);

    if(binarySearch(arr, n, key))
        printf("Element found");
    else
        printf("Element not found");

    return 0;
}