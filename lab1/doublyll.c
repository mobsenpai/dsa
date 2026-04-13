#include <stdio.h>
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

  start->prev = newNode;
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
  newNode->prev = temp;
}

void deleteFirst() {
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

  start = start->next;
  start->prev = NULL;
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

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->prev->next = NULL;
  free(temp);
}

void displayForward() {
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

void displayBackward() {
  struct Node *temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

int main() {
  insertAtFirst(10);
  insertAtFirst(20);
  insertAtEnd(30);
  printf("elements (forwards) -\n");
  displayForward();
  printf("elements (backwards) - \n");
  displayBackward();
  printf("deleted first\n");
  deleteFirst();
  printf("elements -\n");
  displayForward();
  displayBackward();

  return 0;
}
