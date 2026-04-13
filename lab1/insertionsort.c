#include <stdio.h>

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = temp;
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
  insertionSort(arr, 6);
  display(arr, 6);

  return 0;
}
