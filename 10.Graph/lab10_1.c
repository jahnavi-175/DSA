#include <stdio.h>

int main() {
    int n, i, j, count;
    char ch;
    printf("Enter number of vertex: ");
    scanf("%d", &n);
    int adj[n][n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            printf("Vertices %d & %d are Adjacent ? (Y/N): ", i + 1, j + 1);
            scanf(" %c", &ch);
            if (ch == 'y' || ch == 'Y') {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }
    printf("\nVertex\tDegree\n");
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++)
            if (adj[i][j] == 1)
                count++;
        printf("%d\t%d\n", i + 1, count);
    }
    return 0;
}
