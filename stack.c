#include <stdio.h>
// #include <conio.h>

#define MAX 3

int stack[MAX];
int top = -1;

int isEmpty() { return (top == -1) ? 1 : 0; }

int isFull() { return (top == MAX - 1 ? 1 : 0); }

void push(int data) {
  if (isFull()) {
    printf("Stack overflow\n");
  } else {
    stack[++top] = data;
    printf("%d pushed to stack\n", data);
  }
}

int pop() {
  int data;
  if (isEmpty()) {
    printf("Stack underflow\n");
    return -1;
  } else {
    printf("%d removed from stack\n", stack[top]);
    data = stack[top];
    stack[top--] = 0;
    return data;
  }
}

void display() {
  if (isEmpty()) {
    printf("Stack is empty\n");
  } else {
    int i;
    for (i = top; i >= 0; i--) {
      printf("%d\n", stack[i]);
    }
  }
}

int main() {
  push(5);
  push(10);
  push(12);
  printf("Displaying all elements\n");
  display();
  // printf("Popped");
  // pop();
  // printf("Displaying all elements\n");
  // display();
}
