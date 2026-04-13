#include <stdio.h>

#define MAX 5

int arr[MAX];

void selectionSort() {
  int i, j, minIndex;
  int temp;
  for (i = 0; i < MAX - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < MAX; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

// For descending, find maxIndex

void display() {
  int i;
  for (i = 0; i < MAX; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int i;
  printf("Enter %d numbers: ", MAX);
  for (i = 0; i < MAX; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Entered elements - \n");
  display();

  printf("Sorted elements -\n");
  selectionSort();
  display();

  return 0;
}
