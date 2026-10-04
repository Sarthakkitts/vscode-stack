#include<stdio.h>
#include<stdlib.h>

    struct Node{
int data;
struct Node*next;
struct Node*prev;
}*start=NULL;
void create(){
    struct Node*current;
    int n,i;
    printf("enter the elemets to be insterted");
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        struct Node*new_node = (struct Node*)malloc(sizeof(struct Node));
        printf("\n Enter the node data");
        scanf("%d",&new_node->data);
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    


    
