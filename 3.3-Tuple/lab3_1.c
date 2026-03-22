#include <stdio.h>

int main() {
    int m, n, t;
    printf("Enter sparse matrix in 3-tuple format\n");
    scanf("%d %d %d", &m, &n, &t);

    int sp[20][3];   // original sparse matrix
    int trans[20][3]; // transpose matrix

    sp[0][0] = m;
    sp[0][1] = n;
    sp[0][2] = t;

    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &sp[i][0], &sp[i][1], &sp[i][2]);
    }

    // Transpose first line
    trans[0][0] = sp[0][1];  // new rows = old cols
    trans[0][1] = sp[0][0];  // new cols = old rows
    trans[0][2] = sp[0][2];  // number of non-zeros same

    int k = 1;
    // For each column in original, find elements
    for (int col = 0; col < n; col++) {
        for (int i = 1; i <= t; i++) {
            if (sp[i][1] == col) {  // check if element is in this column
                trans[k][0] = sp[i][1];
                trans[k][1] = sp[i][0];
                trans[k][2] = sp[i][2];
                k++;
            }
        }
    }

    // Print result
    printf("Transpose of sparse matrix:\n");
    printf("R C Element\n");
    for (int i = 0; i <= t; i++) {
        printf("%d %d %d\n", trans[i][0], trans[i][1], trans[i][2]);
    }

    return 0;
}
