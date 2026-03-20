#include <stdio.h>
#include <string.h>

// #include <conio.h>

#define MAX 5

struct Job {
  int id;
  char document[50];
};

struct Job cqueue[MAX];
int front = -1, rear = -1;

int isFull() {
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

// enqueue
// instead of char document[], we can also use char *document
void addJob(int id, char document[]) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }

  if (isEmpty()) {
    front = 0;
  }

  rear = (rear + 1) % MAX;
  cqueue[rear].id = id;
  strcpy(cqueue[rear].document, document);
}

// dequeue
void processJob() {
  if (isEmpty()) {
    printf("No jobs in queue\n");
    return;
  }

  printf("Processing: %d [%s]\n", cqueue[front].id, cqueue[front].document);
  if (front == rear) {
    // queue becomes empty
    front = rear = -1;
  } else {
    front = (front + 1) % MAX;
  }
}

void displayJobs() {
  int i;
  if (isEmpty()) {
    printf("No jobs in queue\n");
    return;
  }

  printf("Pending jobs -\n");
  for (i = front; i != rear; i = (i + 1) % MAX) {
    printf("%d [%s]\n", cqueue[i].id, cqueue[i].document);
  }
  printf("%d [%s]\n", cqueue[rear].id, cqueue[rear].document);
}

int main() {
  // clrscr();

  addJob(101, "Report.pdf");
  addJob(102, "Invoice.docx");
  displayJobs();

  processJob();
  displayJobs();

  // getch();
}
