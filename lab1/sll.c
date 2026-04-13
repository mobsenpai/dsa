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
  printf("%d inserted at beginning\n", data);
}

void insertAtEnd(int data) {
  struct Node *newNode = createNode(data);
  struct Node *last = start;
  if (start == NULL) {
    start = newNode;
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }

  last->next = newNode;
  printf("%d inserted at end\n", data);
}

void insertAtPos(int data, int pos) {
  int i;
  struct Node *newNode = createNode(data);
  struct Node *temp = start;
  if (pos == 1) {
    insertAtFirst(data);
    return;
  }

  for (i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position out of range\n");
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
  printf("%d inserted at position %d\n", data, pos);
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
    printf("Last node deleted\n");
    return;
  }

  while (second_last->next->next != NULL) {
    second_last = second_last->next;
  }

  free(second_last->next);
  second_last->next = NULL;
  printf("Last node deleted\n");
}

void display() {
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

struct Node *search(int data) {
  struct Node *current = start;
  while (current != NULL) {
    if (current->data == data) {
      printf("Value %d found in list", data);
      return current;
    }
    current = current->next;
  }

  printf("Value not found\n");
  return NULL;
}

int main() {
  insertAtFirst(10);
  insertAtFirst(20);
  display();
  deleteFirst();
  display();
  search(10);
}
