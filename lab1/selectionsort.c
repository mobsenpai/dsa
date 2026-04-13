#include <stdio.h>

void selectionSort(int arr[], int n) {
  int i, j;
  int min, temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

void display(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[6] = {64, 34, 25, 12, 22, 11};
  selectionSort(arr, 6);
  display(arr, 6);

  return 0;
}
