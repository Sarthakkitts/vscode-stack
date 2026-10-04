#include <stdio.h>

#define MAX 100

int main()
{
    int a[MAX], n = 0;
    int choice, x, pos, i;

    while (1)
    {
        printf("\n1. Insert at End");
        printf("\n2. Insert at Position");
        printf("\n3. Delete at Position");
        printf("\n4. Find");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        /* Insert at End */
        if (choice == 1)
        {
            if (n == MAX)
            {
                printf("Overflow");
            }
            else
            {
                printf("Enter element: ");
                scanf("%d", &x);

                a[n] = x;
                n++;

                printf("Element inserted");
            }
        }

        /* Insert at Position */
        else if (choice == 2)
        {
            printf("Enter position: ");
            scanf("%d", &pos);

            printf("Enter element: ");
            scanf("%d", &x);

            if (pos < 1 || pos > n + 1 || n == MAX)
            {
                printf("Invalid position");
            }
            else
            {
                for (i = n; i >= pos; i--)
                {
                    a[i] = a[i - 1];
                }

                a[pos - 1] = x;
                n++;

                printf("Element inserted");
            }
        }

        /* Delete at Position */
        else if (choice == 3)
        {
            printf("Enter position: ");
            scanf("%d", &pos);

            if (pos < 1 || pos > n)
            {
                printf("Invalid position");
            }
            else
            {
                x = a[pos - 1];

                for (i = pos - 1; i < n - 1; i++)
                {
                    a[i] = a[i + 1];
                }

                n--;

                printf("Deleted element = %d", x);
            }
        }

        /* Find */
        else if (choice == 4)
        {
            printf("Enter element to find: ");
            scanf("%d", &x);

            for (i = 0; i < n; i++)
            {
                if (a[i] == x)
                {
                    printf("Element found at position %d", i + 1);
                    break;
                }
            }

            if (i == n)
                printf("Element not found");
        }

        /* Display */
        else if (choice == 5)
        {
            printf("List: ");

            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
        }

        /* Exit */
        else if (choice == 6)
        {
            break;
        }

        else
        {
            printf("Invalid choice");
        }
    }
    return 0
}