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
  newNode->prev = temp;
}

void insertAtPos(int data, int pos) {
  struct Node *newNode = createNode(data);
  struct Node *temp = start;
  int i;

  if (pos == 1) {
    insertAtFirst(data);
    return;
  }

  for (i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next->prev = newNode;
  temp->next = newNode;
}

void deleteFromFirst() {
  struct Node *temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  if (start->next == NULL) {
    start = NULL;
    free(temp);
    return;
  }

  start = start->next;
  start->prev = NULL;
  free(temp);
}

void deleteFromEnd() {
  struct Node *temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  if (start->next == NULL) {
    start = NULL;
    free(temp);
  }

  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  free(temp->next); // first free it
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
  insertAtPos(13, 2);
  insertAtPos(16, 3);
  display();
}
