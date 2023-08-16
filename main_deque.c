#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Deque.h"

const size_t n = 5;
char *arr[] = {"What is this", "This is a string",
               "In the C programming Language", "Let add this to the list",
               "Jotaru Kujo"};

char *to_heap(char *str, size_t n) {
  char *dest = (char *)malloc((n + 1) * sizeof(char));
  strncpy(dest, str, n);
  dest[n] = '\0';
  return dest;
}

void print_dq(deque_t *dq) {
  node_deque_t *ptr = dq->head;
  int i = 0;
  while (ptr != NULL) {
    printf("[%d] = %s\n", i, (char *)ptr->data);
    ptr = ptr->next;
    i++;
  }
  printf("\n");
}

int main() {
  deque_t dq;
  deque_init(&dq);

  for (int i = 0; i < 5; i++) {
    if (i & 1) {
      deque_push_back(&dq, to_heap(arr[i], strlen(arr[i])));
    } else {
      deque_push_front(&dq, to_heap(arr[i], strlen(arr[i])));
    }
    print_dq(&dq);
    printf("[front] = %s\n", (char *)deque_front(&dq));
    printf("[back] = %s\n", (char *)deque_back(&dq));
  }

  for (int i = 0; i < 5; i++) {
    if (i & 1) {
      deque_pop_back(&dq);
    } else {
      deque_pop_front(&dq);
    }
    print_dq(&dq);
  }

  deque_init(&dq);
  // print_dq(&dq);

  return 0;
}
