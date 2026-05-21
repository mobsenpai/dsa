#include <stdio.h>
// #include <conio.h>

void sort(int arr[], int n) {
  int i, j, key;
  for (i = 1; i < n - 1; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}
