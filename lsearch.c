#include <stdio.h>
// #include <conio.h>

int search(int arr[], int n, int key) {
  int i;
  for (i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {5, 2, 8, 10};
  int key = 8;
  int pos = search(arr, 4, key);
  if (pos != -1) {
    printf("Found at index %d\n", pos);
  } else {
    printf("Not found\n");
  }

  return 0;
}
