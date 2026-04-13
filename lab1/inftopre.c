#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isEmpty() { return top == -1; }

int isFull() { return top == MAX - 1; }

void push(char data) {
  if (isFull()) {
    printf("Stack overflow\n");
    return;
  }

  stack[++top] = data;
}

char pop() {
  if (isEmpty()) {
    printf("Stack underflow\n");
    return '\0';
  }

  return stack[top--];
}

char peek() {
  if (isEmpty()) {
    printf("Stack underflow\n");
    return '\0';
  }

  return stack[top];
}

int precedence(char op) {
  switch (op) {
  // case '^':
  //   return 3;
  case '*':
  case '/':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return 0;
  }
}

void infixToPrefix(char infix[], char prefix[]) {
  int i, j = 0;
  char c;
  char temp[MAX];
  int n1 = strlen(infix);
  int n2;

  for (i = n1 - 1; i >= 0; i--) {
    c = infix[i];
    if (isalnum(c)) {
      temp[j++] = c;
    } else if (c == ')') {
      push(c);
    } else if (c == '(') {
      while (!isEmpty() && peek() != ')') {
        temp[j++] = pop();
      }
      pop();
    } else {
      while (!isEmpty() && precedence(peek()) > precedence(c)) {
        temp[j++] = pop();
      }

      push(c);
    }
  }

  while (!isEmpty()) {
    temp[j++] = pop();
  }

  temp[j] = '\0';

  // reverse
  n2 = strlen(temp);
  for (i = 0, j = n2 - 1; i < n2; i++, j--) {
    prefix[i] = temp[j];
  }

  prefix[i] = '\0';
}

int main() {
  char infix[MAX], prefix[MAX];
  printf("Enter infix expression: ");
  scanf("%s", infix);

  infixToPrefix(infix, prefix);
  printf("prefix: %s", prefix);

  return 0;
}
