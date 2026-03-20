#include <stdio.h>
// #include <conio.h>

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

int isFull() {
  if (rear == MAX - 1) {
    return 1;
  }
  return 0;
}

int isEmpty() {
  if (front == -1) {
    return 1;
  }
  return 0;
}

void enqueue(int data) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }

  if (front == -1) {
    front = 0;
  }

  queue[++rear] = data;
}

int dequeue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }

  int data = queue[front];
  if (front == rear) {
    // queue is empty
    front = rear = -1;
  } else {
    front++;
  }
  return data;
}

void display() {
  int i;
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  for (i = front; i <= rear; i++) {
    printf("%d\t", queue[i]);
  }
}

int main() {
  enqueue(5);
  enqueue(4);
  display();
  printf("\ndequeueing the first element\n");
  dequeue();
  display();

  return 0;
}
