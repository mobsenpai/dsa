#include <stdio.h>

void merge(int leftArr[], int rightArr[], int arr[], int n);

void mergeSort(int arr[], int n) {
  int mid = n / 2;
  int leftArr[mid];
  int rightArr[n - mid];
  int i = 0; // left arr
  int j = 0; // right arr

  if (n <= 1) {
    return;
  }

  for (; i < n; i++) {
    if (i < mid) {
      leftArr[i] = arr[i];
    } else {
      rightArr[j] = arr[i];
      j++;
    }
  }

  mergeSort(leftArr, mid);
  mergeSort(rightArr, n - mid);
  merge(leftArr, rightArr, arr, n);
}

void merge(int leftArr[], int rightArr[], int arr[], int n) {
  int leftSize = n / 2;
  int rightSize = n - leftSize;
  int i = 0, l = 0, r = 0; // indices
  int temp;

  while (l < leftSize && r < rightSize) {
    if (leftArr[l] < rightArr[r]) {
      arr[i] = leftArr[l];
      i++;
      l++;
    } else {
      arr[i] = rightArr[r];
      i++;
      r++;
    }
  }

  while (l < leftSize) {
    arr[i] = leftArr[l];
    i++;
    l++;
  }

  while (r < rightSize) {
    arr[i] = rightArr[r];
    i++;
    r++;
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
  mergeSort(arr, 6);
  display(arr, 6);

  return 0;
}
