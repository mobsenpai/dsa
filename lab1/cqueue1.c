#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }

int isFull() { return (rear + 1) % MAX == front; }

void enqueue(int data) {
  if (isFull()) {
    printf("Queue overflow\n");
    return;
  }

  if (isEmpty()) {
    front = 0;
  }

  rear = (rear + 1) % MAX;
  queue[rear] = data;
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
    front = (front + 1) % MAX;
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

  for (i = front; i != rear; i = (i + 1) % MAX) {
    printf("%d ", queue[i]);
  }
  printf("%d", queue[rear]);
  printf("\n");
}

int main() {
  enqueue(5);
  enqueue(10);
  enqueue(20);
  printf("elements-\n");
  display();
  printf("%d dequeued\n", dequeue());
  printf("elements -\n");
  display();

  return 0;
}
