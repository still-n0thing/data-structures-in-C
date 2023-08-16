#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Vector.h"

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

void print_vec(vector_t *vec) {
  for (int i = 0; i < vec->size; i++) {
    printf("[%d] = %s\n", i, (char *)vec->vec[i]);
  }
  printf("\n");
}

int main() {
  vector_t vec;
  vec_init(&vec);

  for (int i = 0; i < n; i++) {
    vec_push_back(&vec, to_heap(arr[i], strlen(arr[i])));
    print_vec(&vec);
  }

  for (int i = 0; i < n; i++) {
    vec_pop_back(&vec);
    print_vec(&vec);
  }
  vec_cleanup(&vec);

  return 0;
}
