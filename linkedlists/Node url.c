#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* addAtBeg(struct node* tail, int data)
{
    struct node* newP = malloc(sizeof(struct node));

    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;

    return tail;
}


void print(struct node* tail)
{
    struct node* p = tail->next;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    }
    while (p != tail->next);

    printf("\n");
}

int main()
{
    struct node* tail;

    
    tail = malloc(sizeof(struct node));

    tail->data = 10;
    tail->next = tail;
    tail = addAtBeg(tail, 20);
    tail = addAtBeg(tail, 30);
    tail = addAtBeg(tail, 40);
    tail = addAtBeg(tail, 50);
    printf("Circular Linked List: ");
    print(tail);

    return 0;
}