#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() { return top == -1; }

int isFull() { return top == MAX - 1; }

void push(int data) {
  if (isFull()) {
    printf("Stack overflow\n");
    return;
  }

  stack[++top] = data;
}

int pop() {
  if (isEmpty()) {
    printf("Stack underflow\n");
    return -1;
  }

  return stack[top--];
}

int peek() {
  if (isEmpty()) {
    printf("Stack is empty\n");
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

  for (i = top; i >= 0; i--) {
    printf("%d\n", stack[i]);
  }
}

int main() {
  push(4);
  printf("4 pushed\n");
  push(10);
  printf("10 pushed\n");
  push(20);
  printf("20 pushed\n");
  printf("Stack elements top to bottom\n");
  display();
  printf("%d popped\n", pop());
  printf("Stack elements top to bottom\n");
  display();

  return 0;
}
