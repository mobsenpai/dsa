#include <stdio.h>
// #include <conio.h>

void sort(int arr[], int n) {
  int i, j, minIdx;
  int temp;
  for (i = 0; i < n - 1; i++) {
    minIdx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }

    temp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = temp;
  }
}

void display(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {2, 6, 3, 7, 5};
  int n = 5;
  sort(arr, n);

  display(arr, n);

  return 0;
}
