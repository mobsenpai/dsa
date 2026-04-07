#include <stdio.h>

#define COL 2
#define ROW 2

void getElements(int matrix[COL][ROW]) {
  int i, j;
  printf("Enter elements-\n");
  for (i = 0; i < COL; i++) {
    for (j = 0; j < ROW; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void sum(int matrix1[COL][ROW], int matrix2[COL][ROW], int result[COL][ROW]) {
  int i, j;
  for (i = 0; i < COL; i++) {
    for (j = 0; j < ROW; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void display(int matrix[COL][ROW]) {
  int i, j;
  for (i = 0; i < COL; i++) {
    for (j = 0; j < ROW; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int m1[COL][ROW];
  int m2[COL][ROW];
  int m3[COL][ROW];
  getElements(m1);
  getElements(m2);

  sum(m1, m2, m3);

  display(m3);

  return 0;
}
