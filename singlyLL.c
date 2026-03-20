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
  // this is same as writing newNode -> next = NULL if linked list is empty i.e
  // start points to null
  newNode->next = start;
  start = newNode;
}

// leaving other insert methods, for simplicity. will implement later

void deleteFromFirst() {
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = start;
  start = temp->next;
  free(temp);
}

void print() {
  struct Node *temp = start;
  while (temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main() {
  insertAtFirst(3);
  insertAtFirst(4);
  print();
  printf("deleting from first\n");
  deleteFromFirst();
  print();
}
