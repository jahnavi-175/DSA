#include <stdio.h>

int adj[10][10], visited[10], n;

void bfs(int start) {
    int queue[10], front = 0, rear = 0, i;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertex: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter start vertex: ");
    scanf("%d", &start);
    printf("Breadth First Search: ");
    bfs(start);
    return 0;
}
