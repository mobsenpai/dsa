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
    printf("Stack underflow\n");
    return '\0';
  }
  return stack[top];
}

int precedence(char op) {
  switch (op) {
  // skipping for now
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

void infixToPostfix(char infix[], char postfix[]) {
  int i, j = 0;
  char c;
  char data;

  for (i = 0; infix[i] != '\0'; i++) {
    c = infix[i];

    if (isalnum(c)) {
      // if operand, add to output
      postfix[j++] = c;
    } else if (c == '(') {
      // if '(' push to stack
      push(c);
    } else if (c == ')') {
      // if ')' pop until '('
      while ((data = pop()) != '(') {
        postfix[j++] = data;
      }
    } else {
      // operator
      while (precedence(peek()) >= precedence(c)) {
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
  printf("Enter infix expression: ");
  scanf("%s", infix);
  infixToPostfix(infix, postfix);
  printf("%s", postfix);
}
