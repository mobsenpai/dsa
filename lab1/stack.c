#include <stdio.h>

#define MAX 5

int stack[MAX], top = -1;

int isEmpty() { return top == -1; }

int isFull() { return top == MAX - 1; }

void push(int n) {
  if (isFull()) {
    printf("Stack is full\n");
    return;
  }

  stack[++top] = n;
}

int pop() {
  if (isEmpty()) {
    printf("Stack is empty\n");
    return -1;
  }

  printf("%d popped from stack\n", stack[top]);
  return stack[top--];
}

int peek() {
  if (top == -1) {
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

  printf("Stack elements top to bottom\n");
  for (i = top; i >= 0; i--) {
    printf("%d\n", stack[i]);
  }
  printf("\n");
}

int main() {
  int ch, num;
  while (1) {
    printf("Stack operations-\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. "
           "Exit\nEnter choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("Enter element to push: ");
      scanf("%d", &num);
      push(num);
      break;

    case 2:
      pop();
      break;

    case 3:
      printf("%d\n", peek());
      break;

    case 4:
      display();
      break;

    case 0:
      return 0;
      break;

    default:
      printf("Invalid choice\n");
      break;
    }
  }
  return 0;
}
