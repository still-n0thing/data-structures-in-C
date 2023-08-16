#include <stdlib.h>

#include "Vector.h"

#define VEC_START_CAPACITY 1

void vec_init(vector_t *vec) {
  vec->size = vec->capacity = 0;
  vec->vec = NULL;
}

void vec_push_back(vector_t *vec, void *data) {
  if (vec->size == 0) {
    vec->capacity = VEC_START_CAPACITY;
    vec->vec = (void **)malloc(vec->capacity * sizeof(void *));
  } else if (vec->size + 1 >= vec->capacity) {
    vec->capacity *= 2;
    void **new_vec = (void **)malloc(vec->capacity * sizeof(void *));
    for (int i = 0; i < vec->size; i++) {
      new_vec[i] = vec->vec[i];
    }
    void **ptr = vec->vec;
    free(ptr);
    vec->vec = new_vec;
  }
  vec->vec[vec->size] = data;
  vec->size++;
}

void *vec_front(vector_t *vec) { return vec->vec[0]; }

void *vec_back(vector_t *vec) { return vec->vec[vec->size - 1]; }

int vec_pop_back(vector_t *vec) {
  if (vec->size == 0) {
    return 1;
  }
  void *ptr = vec->vec[vec->size - 1];
  vec->vec[vec->size - 1] = NULL;
  vec->size--;
  free(ptr);
  return 0;
}

void vec_cleanup(vector_t *vec) {
  while (vec->size > 0) {
    vec_pop_back(vec);
  }
  free(vec->vec);
}
