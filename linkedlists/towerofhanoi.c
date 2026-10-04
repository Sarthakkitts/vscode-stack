#include <stdio.h>

#define MAX 10

typedef struct
{
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, int disk)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }

    s->data[++s->top] = disk;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }

    return s->data[s->top--];
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }

    return s->data[s->top];
}

void displayTower(Stack *s, char name)
{
    int i;

    printf("Tower %c: ", name);

    if (isEmpty(s))
    {
        printf("Empty");
    }
    else
    {
        for (i = s->top; i >= 0; i--)
        {
            printf("%d ", s->data[i]);
        }
    }

    printf("\n");
}

int moveDisk(Stack *source, Stack *destination, char sourceName, char destinationName)
{
    int sourceDisk;
    int destinationDisk;

    if (isEmpty(source))
    {
        printf("Invalid Move: Tower %c is empty.\n", sourceName);
        return 0;
    }

    sourceDisk = peek(source);
    destinationDisk = peek(destination);

    if (destinationDisk != -1 && sourceDisk > destinationDisk)
    {
        printf("Invalid Move: Disk %d cannot be placed on Disk %d.\n", sourceDisk, destinationDisk);
        return 0;
    }

    sourceDisk = pop(source);
    push(destination, sourceDisk);

    printf("Move Disk %d: %c -> %c\n", sourceDisk, sourceName, destinationName);

    return 1;
}

int main()
{
    Stack A, B, C;
    int n;
    int i;
    int choice;
    int moveCount = 0;

    initialize(&A);
    initialize(&B);
    initialize(&C);

    printf("Enter number of disks (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of disks.\n");
        return 0;
    }

    for (i = n; i >= 1; i--)
    {
        push(&A, i);
    }

    while (1)
    {
        printf("\n");
        displayTower(&A, 'A');
        displayTower(&B, 'B');
        displayTower(&C, 'C');
        printf("Moves: %d\n", moveCount);

        printf("\n1. Move A -> B");
        printf("\n2. Move A -> C");
        printf("\n3. Move B -> A");
        printf("\n4. Move B -> C");
        printf("\n5. Move C -> A");
        printf("\n6. Move C -> B");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (moveDisk(&A, &B, 'A', 'B'))
                    moveCount++;
                break;
            case 2:
                if (moveDisk(&A, &C, 'A', 'C'))
                    moveCount++;
                break;
            case 3:
                if (moveDisk(&B, &A, 'B', 'A'))
                    moveCount++;
                break;
            case 4:
                if (moveDisk(&B, &C, 'B', 'C'))
                    moveCount++;
                break;
            case 5:
                if (moveDisk(&C, &A, 'C', 'A'))
                    moveCount++;
                break;
            case 6:
                if (moveDisk(&C, &B, 'C', 'B'))
                    moveCount++;
                break;
            case 7:
                printf("Game exited.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }

        if (C.top == n - 1)
        {
            printf("\nCongratulations!\n");
            printf("Puzzle Solved!\n");
            printf("Total Moves: %d\n", moveCount);
            break;
        }
    }

    return 0;
}