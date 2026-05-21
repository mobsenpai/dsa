#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *start = NULL;

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
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
  start = newNode;
}

void insertAtEnd(int data) {
  struct Node *newNode = createNode(data);
  struct Node *temp = start;

  if (start == NULL) {
    start = newNode;
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void insertAtPos(int data, int pos) {
  struct Node *newNode = createNode(data);
  struct Node *temp = start;
  int i;

  if (pos == 1) {
    insertAtFirst(data);
    return;
  }

  for (i = 1; i < pos && temp != NULL; i++) {
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteFromFirst() {
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = start;
  if (start->next == NULL) {
    start = NULL;
    free(temp);
  }

  start = start->next;
  free(temp);
}

void deleteFromEnd() {
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = start;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  free(temp->next);
  temp->next = NULL;
}

void display() {
  struct Node *temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

int main() {
  insertAtFirst(5);
  insertAtFirst(10);
  display();

  insertAtEnd(12);
  insertAtEnd(14);
  display();

  deleteFromEnd();
  display();

  deleteFromFirst();
  display();

  insertAtPos(32, 2);
  display();

  return 0;
}
