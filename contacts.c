#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char name[30];
  char ph[11];
  // 11 because one space is for null character '\0'
  char email[20];
  struct Node *next;
};

struct Node *start = NULL;

struct Node *createNode() {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  // either use scanf or strcpy
  // for strcpy take name, ph, email as this func's parameters
  printf("Enter name: ");
  scanf("%s", newNode->name);
  printf("Enter phone number: ");
  scanf("%s", newNode->ph);
  printf("Enter email: ");
  scanf("%s", newNode->email);
  newNode->next = NULL;
  return newNode;
}

void insertAtFirst() {
  struct Node *newNode = createNode();
  newNode->next = start;
  start = newNode;
}

// Dont need to delete from first
// void deleteFromFirst() {
//   struct Node *temp = start;
//   start = temp->next;
//   free(temp);
// }

void deleteContact() {
  struct Node *temp = start, *prev = NULL;
  char target[30];
  printf("Enter name to delete: ");
  scanf("%s", target);

  if (temp == NULL) {
    printf("No contacts to delete\n");
    return;
  }

  // Fount at 1st node (no prev node)
  if (strcmp(temp->name, target) == 0) {
    start = temp->next;
    free(temp);
    return; // important
  }

  // Found anywhere after 1st (has prev node)
  while (temp != NULL) {
    prev = temp;
    temp = temp->next;
    if (temp != NULL && strcmp(temp->name, target) == 0) {
      prev->next = temp->next;
      free(temp);
      return;
    }
  }

  printf("Contact not found\n");
}

void print() {
  struct Node *temp = start;
  printf("Displaying all contacts\n");
  while (temp != NULL) {
    printf("Name: %s\n", temp->name);
    printf("Phone number: %s\n", temp->ph);
    printf("Email: %s\n", temp->email);
    printf("-------------------");
    temp = temp->next;
  }
}

void search() {
  char target[30];
  struct Node *temp = start;
  printf("Enter name to search: ");
  scanf("%s", target);
  while (temp != NULL) {
    int i = 0;
    int match = 1;
    // can you strcmp
    // just demonstrated how to without strcmp
    while (temp->name[i] != '\0' || target[i] != '\0') {
      if (temp->name[i] != target[i]) {
        match = 0;
        break;
      }
      i++;
    }
    if (match == 1) {
      printf("\nFound: %s, %s, %s\n", temp->name, temp->ph, temp->email);
    }
    temp = temp->next;
  }
}

int main() {
  // clrscr();
  insertAtFirst();
  insertAtFirst();
  print();
  search();

  // getch();

  return 0;
}
