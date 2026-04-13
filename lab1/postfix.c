#include <ctype.h>
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
    return '\0';
  }

  return stack[top];
}

int postfix(char exp[]) {
  int i, n1, n2;
  char c;
  for (i = 0; exp[i] != '\0'; i++) {
    c = exp[i];

    if (isdigit(c)) {
      push(c - '0');
    } else {
      n2 = pop();
      n1 = pop();

      switch (c) {
      case '*':
        push(n1 * n2);
        break;
      case '/':
        push(n1 / n2);
        break;
      case '+':
        push(n1 + n2);
        break;
      case '-':
        push(n1 - n2);
        break;
      default:
        break;
      }
    }
  }

  return pop();
}

int main() {
  char exp1[MAX];
  printf("Enter postfix exp: ");
  scanf("%s", exp1);
  printf("Answer: %d", postfix(exp1));
}
