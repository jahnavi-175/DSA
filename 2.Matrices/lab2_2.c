#include <stdio.h>

#define MAX 100

int countNonZero(int mat[][MAX], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
                count++;
    return count;
}

void displayUpperTriangular(int mat[][MAX], int n) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i; k++)
            printf("  ");
        for (int j = i + 1; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void displayDiagonals(int mat[][MAX], int n) {
    printf("Elements just above and below the main diagonal:\n");

    printf("Above Diagonal: ");
    for (int i = 0; i < n - 1; i++)
        printf("%d ", mat[i][i + 1]);
    printf("\n");

    printf("Below Diagonal: ");
    for (int i = 1; i < n; i++)
        printf("%d ", mat[i][i - 1]);
    printf("\n");
}

int main() {
    int mat[MAX][MAX], n;

    printf("Enter size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int nonZeroCount = countNonZero(mat, n);
    printf("Nonzero elements : %d\n", nonZeroCount);

    displayUpperTriangular(mat, n);
    displayDiagonals(mat, n);

    return 0;
}