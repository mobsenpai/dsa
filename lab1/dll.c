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
    printf("%d inserted at beginning\n", data);
    return;
  }

  newNode->next = start;
  start->prev = newNode;
  start = newNode;

  printf("%d inserted at beginning\n", data);
}

void insertAtEnd(int data) {
  struct Node *newNode = createNode(data);
  struct Node *last = start;
  if (start == NULL) {
    start = newNode;
    printf("%d inserted at end\n", data);
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }

  last->next = newNode;
  newNode->prev = last;
  printf("%d inserted at end\n", data);
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
    printf("First node deleted\n");
    return;
  }

  start = start->next;
  start->prev = NULL;
  free(temp);
  printf("First node deleted\n");
}

void deleteLast() {
  struct Node *second_last = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  if (start->next == NULL) {
    free(start);
    start = NULL;
    printf("Last node deleted\n");
    return;
  }

  while (second_last->next->next != NULL) {
    second_last = second_last->next;
  }

  free(second_last->next);
  second_last->next = NULL;
}

void displayForward() {
  struct Node *temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  printf("List elements -\n");
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

  printf("List elements (backwards) -\n");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

int main() {
  insertAtFirst(10);
  insertAtFirst(20);
  displayForward();
  displayBackward();
  deleteFirst();
  displayForward();

  return 0;
}
