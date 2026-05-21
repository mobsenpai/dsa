#include <stdio.h>
// #incluede <conio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX], top = -1;

int isFull() { return (top == MAX - 1) ? 1 : 0; }
int isEmpty() { return (top == -1) ? 1 : 0; }

void push(int data) {
  if (isFull()) {
    printf("Stack overflow\n");
    return;
  }

  stack[++top] = data;
  // printf("%d pushed\n", data);
}

char pop() {
  int data;
  if (isEmpty()) {
    printf("Stack underflow\n");
    return -1;
  }

  data = stack[top];
  // printf("%d popped\n", data);
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

  printf("Stack elements -\n");
  for (i = top; i >= 0; i--) {
    printf("[ %d ]\n", stack[i]);
  }
}

// Infix to postfix
// easier version
int precedence(char op) {
  switch (op) {
  case '*':
  case '/':
    return 2;
    break;
  case '+':
  case '-':
    return 1;
    break;
  default:
    return 0;
  }
}

int isLeftAssociative(char op) { return (op == '^') ? 0 : 1; }

void infixToPostfix(char infix[], char postfix[]) {
  int i, j = 0;
  char ch;
  for (i = 0; infix[i] != '\0'; i++) {
    ch = infix[i];
    if (isalnum(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      push(ch);
    } else if (ch == ')') {
      while (peek() != '(') {
        postfix[j++] = pop();
      }
      pop(); // also remove the bracket
    } else {
      while (precedence(peek()) > precedence(ch) ||
             precedence(peek()) == precedence(ch) && isLeftAssociative(ch)) {
        postfix[j++] = pop();
      }
      push(ch);
    }
  }

  while (!isEmpty()) {
    postfix[j++] = pop();
  }

  postfix[j] = '\0';
}

int main() {
  char infexp[MAX], posexp[MAX];
  printf("Enter infix exp: ");
  scanf("%s", infexp);

  infixToPostfix(infexp, posexp);
  printf("%s", posexp);
}
