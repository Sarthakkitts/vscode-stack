#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
struct Node*prev;
}
*start=NULL;
void create(){
    struct Node*current;
    int n,i;
    printf("enter the elemets to be insterted");
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
     printf("\nEnter the data: ");
      scanf("%d", &new_node->data);
      new_node->next = NULL;
      new_node->prev = NULL;
      if (start == NULL) {
      start = new_node;
      current = new_node;
     } else {
      current->next = new_node;
     new_node->prev = current;
      current=new_node;

    }
}

void delete() {
    if (start == NULL) {
        printf("empty list\n");
        return;
    }
    struct Node* temp = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    free(temp);
}

void printlist() {
    struct Node* temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    create();
    printf("\nThe elements in the double linked list are: ");
    printlist();
    return 0;
}


