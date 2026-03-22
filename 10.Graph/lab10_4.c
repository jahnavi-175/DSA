#include <stdio.h>

int main() {
    int n, i, j;
    char ch;
    printf("Enter number of vertex: ");
    scanf("%d", &n);
    int adj[n][n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("Vertices %d & %d are Adjacent ? (Y/N): ", i + 1, j + 1);
                scanf(" %c", &ch);
                if (ch == 'y' || ch == 'Y')
                    adj[i][j] = 1;
            }
        }
    }
    printf("\nVertex\tIn_Degree\tOut_Degree\tTotal_Degree\n");
    for (i = 0; i < n; i++) {
        int indeg = 0, outdeg = 0;
        for (j = 0; j < n; j++) {
            if (adj[j][i] == 1) indeg++;
            if (adj[i][j] == 1) outdeg++;
        }
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, indeg, outdeg, indeg + outdeg);
    }
    return 0;
}
