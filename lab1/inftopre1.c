#include <ctype.h>
#include <stdio.h>

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
    printf("Stack is empty\n");
    return '\0';
  }

  return stack[top];
}

int precedence(char op) {
  switch (op) {
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
  int i, j = 0, n;
  char c, temp[MAX];

  for (n = 0; infix[n] != '\0'; n++)
    ;
  n--;

  for (i = n; i >= 0; i--) {
    c = infix[i];

    if (isalnum(c)) {
      temp[j++] = c;
    } else if (c == ')') {
      push(c);
    } else if (c == '(') {
      // NOTE: !isEmpty() are needed
      while (!isEmpty() && peek() != ')') {
        temp[j++] = pop();
      }

      pop();
    } else {
      // NOTE: equal precedence should not be popped so only '>'
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
  for (n = 0; temp[n] != '\0'; n++)
    ;
  n--;

  for (i = n, j = 0; i >= 0; i--, j++) {
    prefix[j] = temp[i];
  }

  prefix[j] = '\0';
}

int main() {
  char infix[MAX], prefix[MAX];
  printf("Enter infix exp: ");
  scanf("%s", infix);

  infixToPrefix(infix, prefix);
  printf("Prefix exp: %s", prefix);

  return 0;
}
