#include <stdio.h>

int main() {
    int m1, n1, t1, m2, n2, t2;
    int sp1[20][3], sp2[20][3], res[40][3];

    // Input Sparse Matrix 1
    printf("Enter sparse matrix-1 in 3-tuple format\n");
    scanf("%d %d %d", &m1, &n1, &t1);
    sp1[0][0] = m1; sp1[0][1] = n1; sp1[0][2] = t1;
    for (int i = 1; i <= t1; i++) {
        scanf("%d %d %d", &sp1[i][0], &sp1[i][1], &sp1[i][2]);
    }

    // Input Sparse Matrix 2
    printf("Enter sparse matrix-2 in 3-tuple format\n");
    scanf("%d %d %d", &m2, &n2, &t2);
    sp2[0][0] = m2; sp2[0][1] = n2; sp2[0][2] = t2;
    for (int i = 1; i <= t2; i++) {
        scanf("%d %d %d", &sp2[i][0], &sp2[i][1], &sp2[i][2]);
    }

    // Check dimensions
    if (m1 != m2 || n1 != n2) {
        printf("Matrix dimensions do not match! Cannot add.\n");
        return 0;
    }

    int i = 1, j = 1, k = 1;

    // Add both sparse matrices
    while (i <= t1 && j <= t2) {
        if (sp1[i][0] < sp2[j][0] ||
           (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1])) {
            res[k][0] = sp1[i][0];
            res[k][1] = sp1[i][1];
            res[k][2] = sp1[i][2];
            i++; k++;
        }
        else if (sp2[j][0] < sp1[i][0] ||
                (sp
