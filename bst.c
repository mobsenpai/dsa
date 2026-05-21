#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insert(int data) {
  struct Node *newNode = createNode(data);
  struct Node *temp = root;
  struct Node *parent = NULL;
  if (root == NULL) {
    root = newNode;
    return;
  }

  while (temp != NULL) {
    parent = temp;
    if (data < temp->data) {
      temp = temp->left;
    } else if (data > temp->data) {
      temp = temp->right;
    } else {
      free(newNode);
      return;
    }
  }

  if (data < parent->data) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
}

struct Node *search(int key) {
  struct Node *temp = root;

  while (temp != NULL) {
    if (key == temp->data) {
      return temp;
    } else if (key < temp->data) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }

  return NULL;
}

void inorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

void preorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->data);
  preorder(node->left);
  preorder(node->right);
}

void postorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  postorder(node->left);
  postorder(node->right);
  printf("%d ", node->data);
}

int main() {
  insert(4);
  insert(10);
  insert(2);
  insert(8);
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
}
