#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char url[100];
  struct Node *prev;
  struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *current = NULL;
int size = 0;
int capacity;

Node *createNode(char *url) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->url, url);
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void visit(char *url) {
  if (current != NULL) {
    Node *temp = current->next;
    while (temp != NULL) {
      Node *toDelete = temp;
      temp = temp->next;
      free(toDelete);
      size--;
    }
    current->next = NULL;
    tail = current;
  }

  Node *newNode = createNode(url);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
  current = newNode;
  size++;

  if (size > capacity) {
    Node *oldHead = head;
    head = head->next;
    if (head != NULL)
      head->prev = NULL;
    free(oldHead);
    size--;
  }

  printf("CURRENT -> %s\n", current->url);
}

void back(int k) {
  while (k > 0 && current->prev != NULL) {
    current = current->prev;
    k--;
  }
  printf("CURRENT -> %s\n", current->url);
}

void forward(int k) {
  while (k > 0 && current->next != NULL) {
    current = current->next;
    k--;
  }
  printf("CURRENT -> %s\n", current->url);
}

void showCurrent() { printf("CURRENT -> %s\n", current->url); }

void history() {
  printf("HISTORY -> [");
  Node *temp = head;
  while (temp != NULL) {
    printf("%s", temp->url);
    if (temp->next != NULL)
      printf(", ");
    temp = temp->next;
  }
  printf("]\n");
}

int main() {
  int n;
  printf("Enter capacity N: ");
  scanf("%d", &n);
  capacity = n;

  char command[20], arg[100];

  while (scanf("%s", command) != EOF) {
    if (strcmp(command, "VISIT") == 0) {
      scanf("%s", arg);
      visit(arg);
    } else if (strcmp(command, "BACK") == 0) {
      int k;
      scanf("%d", &k);
      back(k);
    } else if (strcmp(command, "FORWARD") == 0) {
      int k;
      scanf("%d", &k);
      forward(k);
    } else if (strcmp(command, "CURRENT") == 0) {
      showCurrent();
    } else if (strcmp(command, "HISTORY") == 0) {
      history();
    }
  }
  return 0;
}