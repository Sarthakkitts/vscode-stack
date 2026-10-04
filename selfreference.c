#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *node1 = NULL;
    node1 = (struct Node *)malloc(sizeof(struct Node));

    scanf("%d", &node1->data);
    printf("the value of the node1 is %d\n", node1->data);
    node1->next = node1;
    return 0;
}

    



