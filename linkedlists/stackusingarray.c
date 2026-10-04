#include<stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
int isempty(){
return top ==-1;
}
int isfull(){
    return top ==MAX-1;

}
int peek(){
    if(isempty()){
        printf("stack is empty");
        return -1;
    }

    return stack[top];
}
    int pop(){ 
        if(!isempty()){
            printf("stack is empty");
            return -1;
        }
        return stack[top--];
    }

int push(int value){
    if(!isfull()){
        printf("stack is full");
        return -1;
    }
    stack[++top] = value;
    return 0;
}
int main() {
    push(44);
    push(10);
    push(62);
    push(123);
    push(15);
    printf("top element is %d\n",peek());
    printf("pop element is %d\n",pop());
    printf("top element is %d\n",peek());
    return 0;
}