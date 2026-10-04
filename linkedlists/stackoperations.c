#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


char stack[MAX];
int top = -1;


void push(char item) { 
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}


char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}


char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}


int precedence(char symbol) {
    switch(symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}


void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item;
    char x;

    while (infix[i] != '\0') {
        item = infix[i];

        
        if (isalnum(item)) {
            postfix[j++] = item;
        }
        
        else if (item == '(') {
            push(item);
        }
        
        else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
       
        else {
            while (top != -1 && precedence(peek()) >= precedence(item)) {
                // If the top operator has higher or equal precedence, pop it
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }


    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an Infix Expression: ");
    
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
