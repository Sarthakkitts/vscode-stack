#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

/* Create a circular linked list */
struct Node* createList(int n)
{
    struct Node *head = NULL, *cur = NULL, *newNode;
    int i;

    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i);
        scanf("%d", &newNode->num);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            cur = newNode;
        }
        else
        {
            cur->next = newNode;
            cur = newNode;
        }
    }

    /* Make the list circular */
    cur->next = head;

    return head;
}

/* Josephus function */
int josephus(struct Node *head, int k)
{
    struct Node *cur, *pre;
    int i;

    cur = head;/*considering head to 10000*/

    while (cur->next != cur)
    {
        for (i = 1; i <= k; i++)
        {
            pre = cur;
            cur = cur->next;/*current becomes 2000*/
        }

        /* Delete current node */
        pre->next = cur->next;

        printf("%d is killed.\n", cur->num);

        free(cur);

        cur = pre->next;
    }

    return cur->num;
}

int main()
{
    struct Node *head;
    int n, k, survivor;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter k value: ");
    scanf("%d", &k);

    head = createList(n);

    survivor = josephus(head, k);

    printf("\nThe survivor is: %d\n", survivor);

    return 0;
}