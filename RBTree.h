#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <stddef.h>

typedef enum color_rbtree { RBTREE_RED, RBTREE_BLACK } color_rbtree_t;

typedef struct node_rbtree {
  void *data;
  struct node_rbtree *left;
  struct node_rbtree *right;
  struct node_rbtree *parent;
  color_rbtree_t color;
} node_rbtree_t;

typedef struct rbtree {
  node_rbtree_t *root;
  int (*cmp)(void *,
             void *); // -1(left > right), 0(left == right), 1(left < right)
  size_t size;
} rbtree_t;

/*
 * Rules:
 * - Root node is always black
 * - Every node is either red or black
 * - Every leaf (nullptr or NULL) is black
 * - If a node is red then both its children are black
 * - Every simple path from a node to a descendant left contains
 *   the same number of black nodes.
 * ref: https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html
 */

void rbtree_init(rbtree_t *tree, int (*cmp)(void *, void *));
void rbtree_insert(rbtree_t *tree, void *data);
node_rbtree_t *rbteee_find(rbtree_t *tree,
                           void *data); // return nullptr if not found
int rbtree_erase(rbtree_t *tree, void *data);
void rbtree_cleanup(rbtree_t *tree);
// rest would be helper functions

#endif /* _RBTREE_H_ */
