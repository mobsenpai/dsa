#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *start = NULL;

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void insertAtFirst(int data) {
  struct Node *newNode = createNode(data);
  if (start == NULL) {
    start = newNode;
    return;
  }

  newNode->next = start;
  start->prev = newNode;
  start = newNode;
}

void deleteFromFirst() {
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = start;

  if (start->next == NULL) {
    // only one node
    free(start);
    start = NULL;
    return;
  }

  start = start->next;
  start->prev = NULL;
  free(temp);
}

void display() {
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = start;
  while (temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main() {
  insertAtFirst(3);
  insertAtFirst(4);
  insertAtFirst(5);
  display();

  printf("\ndeleting from first\n");
  deleteFromFirst();
  display();
}
