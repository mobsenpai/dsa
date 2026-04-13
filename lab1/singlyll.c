#include <stdio.h>
#include <stdlib.h>

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
  newNode->next = start;
  start = newNode;
}

void insertAtEnd(int data) {
  struct Node *newNode = createNode(data);
  struct Node *temp = start;

  // NOTE: don't forget
  if (start == NULL) {
    start = newNode;
    return;
  }

  // temp = last node
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
}

void deleteFirst() {
  struct Node *temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  // if single node
  if (start->next == NULL) {
    free(start);
    start = NULL;
    return;
  }

  start = start->next;
  free(temp);
}

void deleteLast() {
  struct Node *temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  if (start->next == NULL) {
    free(start);
    start = NULL;
    return;
  }

  // temp = second last node
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

  // don't stop at last node, because we need to print it too
  // hence, temp != NULL
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  insertAtEnd(10);
  insertAtEnd(20);
  insertAtFirst(30);
  printf("elements -\n");
  display();
  printf("delete first\n");
  deleteFirst();
  printf("elements -\n");
  display();
  printf("delete last\n");
  deleteLast();
  printf("elements -\n");
  display();
}
