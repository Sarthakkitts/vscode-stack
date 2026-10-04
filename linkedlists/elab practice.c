#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*next;
    struct node*prev;
    int data;

};
struct node*head=NULL;
void insertend(int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
}struct node*temp=head;
while(temp->next!=NULL){
    temp=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
}
}
void insertbegin(int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    newnode->prev=NULL;
    if(head!=NULL){
        head->prev=newnode;
        head=newnode;    }
}
void delete(int key){
    struct node*temp=head;
    while(temp!=NULL&&temp->data!=key){
        temp=temp->next;
        if (temp==NULL){
            printf("element not found");

        }
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        if(temp->prev!=NULL){
            temp->prev->next=temp->next;
        }
        free(temp);
    }
}
int main(){
    insertend(10);
    insertend(20);
    insertbegin(5);
    delete(10);
    return 0;
}