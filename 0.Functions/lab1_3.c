#include<stdio.h>
#include<string.h>
struct EmDb
{
        char name[100];
        char des[100];
        int salary;
        int hra;
        int da;
        int grsal;
};
int grossSal(int base, int da, int hra)
{
        float gross=0;
        gross = (base + hra/100)+(base + da/100);
        return gross;
};
int main()
{
        int n;
        printf("Enter number of employees:");
        scanf("%d",&n);

        struct EmDb employee[n];
        printf("Enter employee name, designation, salary, hra, da one by one");
        for(int i=0;i<n;i++)
        {
                printf("\nEnter details of employee%d:",i+1);
                scanf("\n%s", employee[i].name);
                scanf("\n%s", employee[i].des);
                scanf("\n%d",&employee[i].salary);
                scanf("\n%d",&employee[i].hra);
                scanf("\n%d",&employee[i].da);

                float gross = grossSal(employee[i].salary,employee[i].da,employee[i].hra);
                printf("Gross Salary: %f\n",gross);
        }
        return 0;
}