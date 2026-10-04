#include <stdio.h>

#define MAX 100

int list[MAX];
int size = 0;

/* Insert element at the end */
void insertAtEnd(int x)
{
    if (size == MAX)
    {
        printf("Overflow\n");
        return;
    }

    list[size] = x;
    size++;

    printf("%d inserted at the end.\n", x);
}

/* Insert element at a given position */
void insertAtPos(int pos, int x)
{
    int i;

    /* Position is 1-based */
    if (size == MAX || pos < 1 || pos > size + 1)
    {
        printf("Invalid position or Overflow\n");
        return;
    }

    /* Shift elements to the right */
    for (i = size; i >= pos; i--)
    {
        list[i] = list[i - 1];
    }

    list[pos - 1] = x;
    size++;

    printf("%d inserted at position %d.\n", x, pos);
}

/* Delete element at a given position */
void deleteAtPos(int pos)
{
    int removed, i;

    /* Position is 1-based */
    if (pos < 1 || pos > size)
    {
        printf("Invalid position\n");
        return;
    }

    removed = list[pos - 1];

    /* Shift elements to the left */
    for (i = pos - 1; i < size - 1; i++)
    {
        list[i] = list[i + 1];
    }

    size--;

    printf("%d deleted from position %d.\n", removed, pos);
}

/* Find an element */
void find(int x)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (list[i] == x)
        {
            printf("Element %d found at position %d.\n", x, i + 1);
            return;
        }
    }

    printf("NOT_FOUND\n");
}

/* Display the list */
void display()
{
    int i;

    if (size == 0)
    {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");

    for (i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }

    printf("\n");
}

/* Main function */
int main()
{
    int choice;
    int x, pos;

    while (1)
    {
        printf("\n===== ARRAY BASED LIST =====\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Position\n");
        printf("3. Delete at Position\n");
        printf("4. Find\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);

                insertAtEnd(x);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);

                printf("Enter element: ");
                scanf("%d", &x);

                insertAtPos(pos, x);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                deleteAtPos(pos);
                break;

            case 4:
                printf("Enter element to find: ");
                scanf("%d", &x);

                find(x);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}