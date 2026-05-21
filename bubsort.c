#include <stdio.h>
// #include <conio.h>

void sort(int arr[], int n) {
  int i, j;
  int temp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void display(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[] = {2, 5, 3, 8, 6};
  sort(arr, 5);
  display(arr, 5);

  return 0;
}
