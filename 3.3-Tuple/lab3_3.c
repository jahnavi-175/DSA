#include <stdio.h>

int main() {
    int deg, i;
    printf("Enter maximum degree of x: ");
    scanf("%d", &deg);

    int poly1[deg + 1], poly2[deg + 1], result[deg + 1];

    printf("Enter Polynomial-1 from lowest degree to highest degree : ");
    for (i = 0; i <= deg; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter Polynomial-2: ");
    for (i = 0; i <= deg; i++) {
        scanf("%d", &poly2[i]);
    }

    // Add polynomials
    for (i = 0; i <= deg; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    // Print result (from highest degree to lowest)
    printf("Resultant Polynomial: ");
    for (i = deg; i >= 0; i--) {
        printf("%dx^%d", result[i], i);
        if (i > 0) printf("+");
    }
    printf("\n");

    return 0;
}
