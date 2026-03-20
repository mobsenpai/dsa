#include <stdio.h>
#include <stdlib.h>

// forward declaration
// struct Node;

// struct Node {
//   int data;
//   struct Node *next;
// }

struct Node {
  int data;
  // This is possible with pointer only
  // as this won't work
  // struct Node hello;
  // because we still haven't assigned memory to it,
  // i.e created a variable using this user defined data type
  // or we could use forward declaration, as demonstrated above
  struct Node *next;
};

struct Node *start = NULL;
// start = (struct Node *)malloc(sizeof(struct Node));

void create() {
  start = (struct Node *)malloc(sizeof(struct Node));
  int n = 8; // for testing
  start->data = n;
  start->next = NULL;
}

void insertAtEnd(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  struct Node *temp = start;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}
