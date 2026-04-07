#include <stdio.h>

#define MAX 5

int arr[MAX];

int main() {
  int i, sum = 0;
  printf("Enter 5 numbers: ");
  for (i = 0; i < MAX; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  printf("Entered numbers -\n");
  for (i = 0; i < MAX; i++) {
    printf("%d\t", arr[i]);
  }

  printf("\nSum=%d", sum);
  return 0;
}
