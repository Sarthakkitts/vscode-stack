#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
/* Create a new node */
struct Node* createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
/* Insert node at the end */
struct Node* insert(struct Node *head, int value)
{
    struct Node *newNode, *temp;
    newNode = createNode(value);
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
/* Display linked list */
void display(struct Node *head)
{
    struct Node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    struct Node *head = NULL;
    int n, i, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("\nLinked List:\n");
    display(head);
    return 0;
}