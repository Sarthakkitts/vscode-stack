#include <stdio.h>

struct Student
{
    int id;
    char name[30];
    int age;
    int marks[5];
    int total;
    float average;
    char grade;
};

int main()
{
    int n, i, j, maxTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Age: ");
        scanf("%d", &s[i].age);

        printf("Enter Marks in 5 subjects:\n");

        s[i].total = 0;

        for(j = 0; j < 5; j++)
        {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].average = s[i].total / 5.0;

        if(s[i].average >= 90)
            s[i].grade = 'O';
        else if(s[i].average >= 80)
            s[i].grade = 'A';
        else if(s[i].average >= 70)
            s[i].grade = 'B';
        else if(s[i].average >= 60)
            s[i].grade = 'C';
        else
s[i].grade = 'F';

        if(s[i].total > maxTotal)
            maxTotal = s[i].total;
    }

    printf("\nStudent Details\n");

    for(i = 0; i < n; i++)
    {
        printf("%d %s Total=%d Average=%.2f Grade=%c\n",
               s[i].id, s[i].name,
               s[i].total, s[i].average,
               s[i].grade);
    }

    printf("\nTopper(s)\n");

    for(i = 0; i < n; i++)
    {
        if(s[i].total == maxTotal)
        {
            printf("%d %s Total=%d Grade=%c\n",
                   s[i].id,
                   s[i].name,
                   s[i].total,
                   s[i].grade);
        }
    }

    return 0;
}