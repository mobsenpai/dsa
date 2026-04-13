#include <stdio.h>

#define MAX 5

int arr[MAX];

void insertionSort() {
  int i, j;
  int temp;

  for (i = 1; i < MAX; i++) {
    temp = arr[i];

    int j = i - 1;
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

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
  insertionSort();
  display();

  return 0;
}
