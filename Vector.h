#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stddef.h>

typedef struct vector {
  size_t size;
  size_t capacity;
  void **vec;
} vector_t;

void vec_init(vector_t *vec);
void vec_push_back(vector_t *vec, void *data);
void *vec_front(vector_t *vec);
void *vec_back(vector_t *vec);
int vec_pop_back(vector_t *vec);
void vec_cleanup(vector_t *vec);

#endif /* _VECTOR_H_ */
