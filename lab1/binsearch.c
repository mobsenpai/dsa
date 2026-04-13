#include <stdio.h>

#define MAX 5

int arr[MAX];

// TODO: add bubble sort here

int binarySearch(int num) {
  int low = 0, mid, high = MAX - 1;
  int i;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == num) {
      return mid;
    }

    if (num < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

int main() {
  int i;
  int item;
  int result;

  printf("Enter %d numbers: ", MAX);
  for (i = 0; i < MAX; i++) {
    scanf("%d", &arr[i]);
  }

  // TODO: call bubble sort

  printf("Enter num to search: ");
  scanf("%d", &item);

  result = binarySearch(item);
  if (result != -1) {
    printf("Found at index %d\n", result);
  } else {
    printf("Num not found\n");
  }

  return 0;
}
