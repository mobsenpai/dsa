#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }

int isFull() { return rear == MAX - 1; }

void enqueue(int data) {
  if (isFull()) {
    printf("Queue overflow\n");
    return;
  }

  if (isEmpty()) {
    front = 0;
  }

  queue[++rear] = data;
}

int dequeue() {
  int data;

  if (isEmpty()) {
    printf("Queue underflow\n");
    return -1;
  }

  data = queue[front];

  // NOTE: don't forget this
  if (front == rear) {
    front = rear = -1;
  } else {
    front++;
  }

  return data;
}

int peek() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }

  return queue[front];
}

void display() {
  int i;
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  for (i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  enqueue(5);
  enqueue(10);
  enqueue(20);
  printf("elements -\n");
  display();
  printf("%d dequed", dequeue());
  printf("elements -\n");
  display();
}
