#include <stdio.h>
// #include <conio.h>
#include <math.h>

#define MAX 5

float stack[MAX];
int top = -1;

void push(int n) {
  if (top >= MAX - 1) {
    printf("Stack overflow\n");
    return;
  }

  stack[++top] = n;
}

float pop() {
  float data;
  if (top == -1) {
    printf("Stack underflow\n");
    return -1;
  }

  data = stack[top];
  stack[top--] = 0;
  return data;
}

void display() {
  int i;
  if (top == -1) {
    printf("Nothing to show");
    return;
  }

  for (i = top; i >= 0; i--) {
    printf("%f\n", stack[i]);
  }
}

int isDigit(int ch) {
  if (ch >= '0' && ch <= '9') {
    return 1;
  }

  return 0;
}

void postfix(char expression[]) {
  char *ptr = expression;
  float n1, n2, n3;
  while (*ptr != '\0') {
    if (isDigit(*ptr)) {
      push(*ptr - '0');
    } else {
      n2 = pop();
      n1 = pop();
      switch (*ptr) {
      case '+':
        n3 = n1 + n2;
        break;
      case '-':
        n3 = n1 - n2;
        break;
      case '*':
        n3 = n1 * n2;
        break;
      case '/':
        n3 = n1 / n2;
        break;
      case '^':
        n3 = pow(n1, n2);
        break;
      }

      push(n3);
    }

    ptr++;
  }

  printf("\nResult = %f", pop());
}

int main() {
  // clrscr();
  postfix("532*+");

  // getch();
  return 0;
}
