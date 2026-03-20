#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
  char title[20];
  struct Song *prev;
  struct Song *next;
};

struct Song *start = NULL;
struct Song *current = NULL;

struct Song *createSong(char title[]) {
  struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
  strcpy(newSong->title, title);
  newSong->prev = NULL;
  newSong->next = NULL;
  return newSong;
}

// this inserted at beginning
// we don't want that. we want to insert at end
// void addSong(char title[]) {
//   struct Song *newSong = createSong(title);
//   if (start == NULL) {
//     start = newSong;
//     current = newSong;
//     return;
//   }

//   start->prev = newSong;
//   newSong->next = start;
//   start = newSong;
// }

// insert song at end
void addSong(char title[]) {
  struct Song *newSong = createSong(title);
  if (start == NULL) {
    start = newSong;
    current = newSong;
    return;
  }

  struct Song *temp = start;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newSong;
  newSong->prev = temp;
}

void deleteSong(char title[]) {
  if (start == NULL) {
    printf("Playlist is empty\n");
    return;
  }

  struct Song *temp = start;
  while (temp != NULL && (strcmp(temp->title, title) != 0)) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Song not found\n");
    return;
  }

  if (temp == start) {
    start = start->next;
    if (start != NULL) {
      start->prev = NULL;
    }
  } else {
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
      temp->next->prev = temp->prev;
    }
  }

  // if deleted song was current one, move current to next or pervious
  if (temp == current) {
    if (temp->next != NULL) {
      current = temp->next;
    } else {
      current = temp->prev;
    }
  }

  free(temp);
}

void nextSong() {
  if (current == NULL) {
    printf("No song playing\n");
    return;
  }

  if (current->next == NULL) {
    printf("This is the last song\n");
    return;
  }

  current = current->next;
  printf("Now playing next: [%s]\n", current->title);
}

void prevSong() {
  if (current == NULL) {
    printf("No song playing\n");
    return;
  }

  if (current->prev == NULL) {
    printf("This is the first song\n");
    return;
  }

  current = current->prev;
  printf("Now playing previous: [%s]\n", current->title);
}

void showStatus() {
  if (current == NULL) {
    printf("Playlist empty\n");
    return;
  }

  printf("Now playing: [%s]\n", current->title);
}

int main() {
  // clrscr();

  addSong("Dream on");
  addSong("Believer");
  addSong("Alone");
  showStatus();
  nextSong();
  showStatus();
  printf("Deleting songs-\n");
  deleteSong("Believer");
  showStatus();
  // getch();
  return 0;
}
