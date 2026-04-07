#include <stdio.h>

#define MAX 5

void getElements(int arr[]) {
  printf("Enter %d elements -\n", MAX);
  int i;
  for (i = 0; i < MAX; i++) {
    scanf("%d", &arr[i]);
  }
}

void display(int arr[]) {
  int i;
  for (i = 0; i < MAX; i++) {
    printf("%d\t", arr[i]);
  }
}

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

int main() {
  int arr[MAX];

  getElements(arr);
  sort(arr);
  display(arr);

  return 0;
}
