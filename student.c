#include <stdio.h>

#define MAX 5

struct student {
  int roll;
  char name[20];
  float marks;
};

struct student arr[MAX];
int count;

void addStudent() {
  if (count == MAX) {
    printf("Array is full");
    return;
  }

  printf("Enter student roll: ");
  scanf("%d", &arr[count].roll);
  printf("Enter student name: ");
  scanf("%s", arr[count].name);
  printf("Enter marks: ");
  scanf("%f", &arr[count].marks);

  count++;
}

void deleteStudent() {
  int roll, i, j;
  if (count == 0) {
    printf("No records to delete");
    return;
  }

  printf("Enter roll no of student to delete: ");
  scanf("%d", &roll);
  for (i = 0; i < count; i++) {
    if (roll == arr[i].roll) {
      for (j = i; j < count - 1; j++) {
        arr[j] = arr[j + 1];
      }

      count--;
      return;
    }
  }

  printf("Student with given roll no not found");
}

void searchStudent() {
  if (count == 0) {
    printf("No records found");
    return;
  }

  int roll, i;
  printf("Enter roll no to search: ");
  scanf("%d", &roll);
  for (i = 0; i < count; i++) {
    if (roll == arr[i].roll) {
      printf("Student Found\n");
      printf("Name: %s\n", arr[i].name);
      printf("Roll: %d\n", arr[i].roll);
      printf("Marks: %f\n", arr[i].marks);
      return;
    }
  }

  printf("Student with given roll not found");
}

void displayAll() {
  int i;
  if (count == 0) {
    printf("No records found");
    return;
  }

  printf("All students - \n");
  for (i = 0; i < count; i++) {
    printf("Name: %s\n", arr[i].name);
    printf("Roll: %d\n", arr[i].roll);
    printf("Marks: %f\n", arr[i].marks);
    printf("----------------------");
  }
}

int main() {
  int ch;
  while (1) {
    printf("Enter\n1. Add student\n2. Remove student\n3. Search student\n4. "
           "Display all students\n0. Exit");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      addStudent();
      break;
    case 2:
      deleteStudent();
      break;
    case 3:
      searchStudent();
      break;
    case 4:
      displayAll();
      break;
    case 0:
      return 0;
    default:
      printf("Invalid choice");
      break;
    }
  }
}
