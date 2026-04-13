#include <stdio.h>

#define MAX 5

int arr[MAX];

void bubbleSort() {
  int i, j;
  int temp;
  for (i = 0; i < MAX - 1; i++) {
    for (j = 0; j < MAX - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// For descending, use arr[j] < arr[j+1]

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
  bubbleSort();
  display();

  return 0;
}
