#include <stdio.h>
// #include <conio.h>

int search(int arr[], int n, int key) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (key == arr[mid]) {
      return mid;
    } else if (key < arr[mid]) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return -1;
}

int main() {
  int arr[] = {2, 4, 6, 8, 12}; // needs sorted elements
  int pos = search(arr, 5, 8);
  if (pos != -1) {
    printf("Found at %d\n", pos);
  } else {
    printf("Not found\n");
  }

  return 0;
}
