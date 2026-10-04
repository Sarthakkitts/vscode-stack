#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node addatbeg(struct node *tail,int data){
struct node* newP = malloc(sizeof(struct node));
newP->data = data;
newP->next = tail->next;
tail->next = newP;
return tail;
}

void print(struct node *tail){
    struct node* p = tail ->next;
    do
    {
        printf("%d",p->data);
        p = p->next;

    } while (p != tail->next);
    printf("\n");

}
int main(){
    struct node *tail = malloc(sizeof(struct node));
    tail->data = 100;
    tail->next = tail;
    tail = addatbeg(tail,200);
    tail = addatbeg(tail,300);
    tail = addatbeg(tail,400);
    printf(tail);


}

