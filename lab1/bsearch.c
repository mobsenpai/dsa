#include <stdio.h>

#define MAX 5

void getElements(int arr[]) {
  int i;
  printf("Enter %d elements -\n", MAX);
  for (i = 0; i < MAX; i++) {
    scanf("%d", &arr[i]);
  }
}

// Array need to be sorted
// For binary search
void sort(int arr[]) {
  int i, j, temp;
  for (i = 0; i < MAX - 1; i++) {
    for (j = i + 1; j < MAX; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int binarySearch(int arr[], int num) {
  int high = MAX - 1, low = 0, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (num < arr[mid]) {
      high = mid - 1;
    } else if (num > arr[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

void display(int arr[]) {
  int i;
  for (i = 0; i < MAX; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[MAX], num, result;
  getElements(arr);
  sort(arr);
  printf("Sorted array -\n");
  display(arr);

  printf("Enter number to find: ");
  scanf("%d", &num);

  result = binarySearch(arr, num);
  if (result != -1) {
    printf("Found result at index: %d", result);
  } else {
    printf("Not Found\n");
  }
}
