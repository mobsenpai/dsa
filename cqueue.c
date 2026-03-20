#include <stdio.h>
// #include <conio.h>

#define MAX 5

// All is same as simple queue
// just use these for update
//  front = (front + 1 ) % MAX
//  rear = (rear + 1) % MAX

int cqueue[MAX];
int front = -1, rear = -1;

int isFull() {
  // can use size variable to count number of items in queue
  // to check if is it full or not , as well
  if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
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

  if (isEmpty()) {
    front = 0;
  }

  rear = (rear + 1) % MAX;
  cqueue[rear] = data;
}

int dequeue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }

  int data = cqueue[front];
  if (front == rear) {
    // queue is empty
    front = rear = -1;
  } else {
    front = (front + 1) % MAX;
  }

  return data;
}

void display() {
  int i;
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  // 1st way to display
  // if (front <= rear) {
  //   for (i = front; i <= rear; i++) {
  //     printf("%d\t", cqueue[i]);
  //   }
  // } else {
  //   for (i = front; i < MAX; i++) {
  //     printf("%d\t", cqueue[i]);
  //   }

  //   for (i = 0; i <= rear; i++) {
  //     printf("%d\t", cqueue[i]);
  //   }
  // }
  // --------------------------------------

  // 2nd way to display
  for (i = front; i != rear; i = (i + 1) % MAX) {
    printf("%d\t", cqueue[i]);
  }
  printf("%d\t", cqueue[rear]); // print the last element
  // ---------------------------------------
}

int main() {
  // clrscr();

  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6);
  enqueue(7);
  display();

  printf("\ndeleted\n");
  dequeue();
  display();

  printf("\nadded\n");
  enqueue(8);
  display();

  // getch();
}
