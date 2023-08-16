#include <stdlib.h>

#include "Deque.h"

void deque_init(deque_t *dq) {
  dq->size = 0;
  dq->head = dq->tail = NULL;
}

void deque_push_back(deque_t *dq, void *data) {
  if (dq->size == 0) {
    node_deque_t *element = (node_deque_t *)malloc(sizeof(node_deque_t));
    element->data = data;
    element->next = NULL;
    element->prev = NULL;
    dq->head = element;
    dq->tail = element;
  } else {
    node_deque_t *element = (node_deque_t *)malloc(sizeof(node_deque_t));
    element->data = data;
    element->next = NULL;
    element->prev = dq->tail;
    dq->tail->next = element;
    dq->tail = element;
  }
  dq->size++;
}

void deque_push_front(deque_t *dq, void *data) {
  if (dq->size == 0) {
    node_deque_t *element = (node_deque_t *)malloc(sizeof(node_deque_t));
    element->data = data;
    element->next = NULL;
    element->prev = NULL;
    dq->head = element;
    dq->tail = element;
  } else {
    node_deque_t *element = (node_deque_t *)malloc(sizeof(node_deque_t));
    element->data = data;
    element->prev = NULL;
    element->next = dq->head;
    dq->head->prev = element;
    dq->head = element;
  }
  dq->size++;
}

void *deque_front(deque_t *dq) { return dq->head->data; }

void *deque_back(deque_t *dq) { return dq->tail->data; }

int deque_pop_front(deque_t *dq) {
  if (dq->size == 0) {
    return 1;
  } else if (dq->size == 1) {
    node_deque_t *element = dq->head;
    dq->head = dq->tail = NULL;
    free(element->data);
    free(element);
  } else {
    node_deque_t *element = dq->head;
    dq->head = element->next;
    dq->head->prev = NULL;
    free(element->data);
    free(element);
  }
  dq->size--;
  return 0;
}

int deque_pop_back(deque_t *dq) {
  if (dq->size == 0) {
    return 1;
  } else if (dq->size == 1) {
    node_deque_t *element = dq->tail;
    dq->head = dq->tail = NULL;
    free(element->data);
    free(element);
  } else {
    node_deque_t *element = dq->tail;
    dq->tail = element->prev;
    dq->tail->next = NULL;
    free(element->data);
    free(element);
  }
  dq->size--;
  return 0;
}
