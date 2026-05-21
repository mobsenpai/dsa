#include <stdio.h>
// #include <conio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// after wrapping does it still come to front?
// yes - full
// no - not full
int isFull() { return ((rear + 1) % MAX == front) ? 1 : 0; }
int isEmpty() { return (front == -1) ? 1 : 0; }

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
    printf("Stack underflow\n");
    return -1;
  }

  data = queue[front];

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

  printf("Queue elements -\n");
  for (i = front; i != rear; i = (i + 1) % MAX) {
    printf("%d ", queue[i]);
  }
  printf("%d", queue[rear]);
  printf("\n");
}

int main() {
  enqueue(5);
  enqueue(10);
  enqueue(13);
  display();
  dequeue();
  dequeue();
  display();
}
