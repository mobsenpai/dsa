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

char precedence(char op) {
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

void infixToPostfix(char infix[], char postfix[]) {
  int i, j = 0;
  char c;
  for (i = 0; infix[i] != '\0'; i++) {
    c = infix[i];

    if (isalnum(c)) {
      postfix[j++] = c;
    } else if (c == '(') {
      push(c);
    } else if (c == ')') {
      while (peek() != '(') {
        postfix[j++] = pop();
      }

      pop();
    } else {
      while (!isEmpty() && precedence(peek()) >= precedence(c)) {
        postfix[j++] = pop();
      }

      push(c);
    }
  }

  while (!isEmpty()) {
    postfix[j++] = pop();
  }

  postfix[j] = '\0';
}

int main() {
  char infix[MAX], postfix[MAX];
  printf("Enter infix exp: ");
  scanf("%s", infix);
  infixToPostfix(infix, postfix);
  printf("Postfix: %s\n", postfix);
  return 0;
}
