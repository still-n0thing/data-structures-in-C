#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <stddef.h>

typedef struct node_deque {
  void *data;
  struct node_deque *next;
  struct node_deque *prev;
} node_deque_t;

typedef struct deque {
  node_deque_t *head;
  node_deque_t *tail;
  size_t size;
} deque_t;

void deque_init(deque_t *dq);
void deque_push_back(deque_t *dq, void *data);
void deque_push_front(deque_t *dq, void *data);
void *deque_front(deque_t *dq);
void *deque_back(deque_t *dq);
int deque_pop_front(deque_t *dq);
int deque_pop_back(deque_t *dq);

#endif /* _DEQUE_H_ */
