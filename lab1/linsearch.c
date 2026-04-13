#include <stdio.h>

#define MAX 5

int arr[MAX];

int linearSearch(int num) {
  int i;
  for (i = 0; i < MAX; i++) {
    if (arr[i] == num) {
      return i;
    }
  }

  return -1;
}

int main() {
  int i, item;
  int result;

  printf("Enter %d numbers: ", MAX);
  for (i = 0; i < MAX; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter num to search : ");
  scanf("%d", &item);

  result = linearSearch(item);
  if (result != -1) {
    printf("Found at index %d", result);
  } else {
    printf("Not found\n");
  }

  return 0;
}
