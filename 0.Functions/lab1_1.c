#include<stdio.h>

void compare(int *a, int *b)
{
        if(*a > *b)
                printf("%d is greater.",*a);

        else if(*b > *a)
                printf("%d is greater.",*b);

        else
                printf("Both %d and %d are equal.",*a,*b);
}

void compare(int *a, int *b);

int main()
{
        int a,b;
        printf("Enter two numbers:");
        scanf("%d%d",&a,&b);
        compare(&a , &b);
        return 0;
}
