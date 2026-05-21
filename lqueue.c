#include <stdio.h>
// #include <conio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

int isEmpty() { return (front == -1) ? 1 : 0; }

int isFull() { return (rear == MAX - 1) ? 1 : 0; }

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
  int data; // necessary for queue
  if (isEmpty()) {
    printf("Stack underflow\n");
    return -1;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  }

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

  printf("Queue elements -\n");
  for (i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
}

int main() {
  enqueue(5);
  enqueue(6);
  display();
  dequeue();
  dequeue();
  display();
  return 0;
}
