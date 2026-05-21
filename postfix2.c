// NOTE:
// We take string as postifx expression
// Only evaluation as numbers is possible for this level
// So everything is numeric except the postfix expression string which we get
// So need to convert the string numbers back to number type
// char - '0'

#include <stdio.h>
// #include <conio.h>
#include <ctype.h>

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
}

int pop() {
  int data;
  if (isEmpty()) {
    printf("Stack underflow\n");
    return -1;
  }

  data = stack[top];
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

void postfix(char exp[]) {
  int i;
  char ch;
  int a, b, res;
  for (i = 0; exp[i] != '\0'; i++) {
    ch = exp[i];

    if (isdigit(ch)) {
      push(ch - '0');
    } else {
      b = pop();
      a = pop();

      switch (ch) {
      case '/':
        res = a / b;
        break;
      case '*':
        res = a * b;
        break;
      case '+':
        res = a + b;
        break;
      case '-':
        res = a - b;
        break;
      }

      push(res);
    }
  }

  printf("Evaluation: %d", pop());
}

int main() {
  char value[MAX];
  printf("Enter postfix exp: ");
  scanf("%s", value);

  postfix(value);
  return 0;
}
