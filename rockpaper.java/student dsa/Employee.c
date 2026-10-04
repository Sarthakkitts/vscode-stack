#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[30];
    char department[30];
    int salary;
};

int main()
{
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee *emp;

    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    if(emp == NULL)
    {
        printf("Memory Allocation Failed");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Name: ");
        scanf("%s", emp[i].name);

        printf("Enter Department: ");
        scanf("%s", emp[i].department);

        printf("Enter Salary: ");
        scanf("%d", &emp[i].salary);
    }

    printf("\nEmployee Details\n");

    for(i = 0; i < n; i++)
    {
        printf("%d %s %s %d\n",
               emp[i].id,
               emp[i].name,
               emp[i].department,
               emp[i].salary);
    }

 int maxSalary = emp[0].salary;
    int index = 0;

    for(i = 1; i < n; i++)
    {
        if(emp[i].salary > maxSalary)
        {
            maxSalary = emp[i].salary;
            index = i;
        }
        else if(emp[i].salary == maxSalary &&
                emp[i].id < emp[index].id)
        {
            index = i;
        }
    }

    printf("\nHighest Paid Employee\n");
    printf("%d %s %s %d\n",
           emp[index].id,
           emp[index].name,
           emp[index].department,
           emp[index].salary);

    free(emp);

    return 0;
}