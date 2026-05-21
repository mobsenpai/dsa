#include <stdio.h>
// #incluede <conio.h>

#define MAX 100

int stack[MAX], top = -1;

int isFull() { return (top == MAX - 1) ? 1 : 0; }
int isEmpty() { return (top == -1) ? 1 : 0; }

void push(int data) {
  if (isFull()) {
    printf("Stack overflow\n");
    return;
  }

  stack[++top] = data;
  printf("%d pushed\n", data);
}

int pop() {
  int data;
  if (isEmpty()) {
    printf("Stack underflow\n");
    return -1;
  }

  data = stack[top];
  printf("%d popped\n", data);
  return stack[top--];
}

int peek() {
  if (isEmpty()) {
    return -1;
  }
  return stack[top];
}

void display() {
  int i;
  if (isEmpty()) {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack elements -\n");
  for (i = top; i >= 0; i--) {
    printf("[ %d ]\n", stack[i]);
  }
}

int main() {
  push(10);
  push(12);
  push(20);
  display();

  pop();
  display();
}
