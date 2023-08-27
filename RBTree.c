#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "RBTree.h"

void rbtree_init(rbtree_t *tree, int (*cmp)(void *, void *)) {
  tree->root = NULL;
  tree->size = 0;
  tree->cmp = cmp;
}

static color_rbtree_t uncle_color(node_rbtree_t *node) {
  node_rbtree_t *parent = node->parent;
  node_rbtree_t *grand_parent = parent->parent;
  if (grand_parent->left != parent) {
    if (grand_parent->left == NULL)
      return RBTREE_BLACK; // leaf node are black in RBTree
    else
      return grand_parent->left->color;
  } else if (grand_parent->right != parent) {
    if (grand_parent->right == NULL)
      return RBTREE_BLACK; // leaf node are black in RBTree
    else
      return grand_parent->right->color;
  }
  assert(0);
}

void rbtree_insert(rbtree_t *tree, void *data) {
  if (tree->size == 0) {
    node_rbtree_t *element = (node_rbtree_t *)malloc(sizeof(node_rbtree_t));
    element->data = data;
    element->color = RBTREE_BLACK;
    element->parent = NULL;
    element->left = NULL;
    element->right = NULL;
    tree->root = element;
  } else {
    node_rbtree_t *ptr = tree->root;
    int dir = 0; // -1 left and 1 right

    while (1) {
      int cmp = tree->cmp(ptr->data, data);
      if (cmp == -1) {
        if (ptr->left == NULL) {
          dir = -1;
          break;
        } else {
          ptr = ptr->left;
        }
      } else if (cmp == 0) {
        // Element already exits
        return;
      } else if (cmp == 1) {
        if (ptr->right == NULL) {
          dir = 1;
          break;
        } else {
          ptr = ptr->right;
        }
      } else {
        fprintf(stderr,
                "ERROR: [FILE: %s] [LINE: %d] Incorrect implementation of cmp "
                "function\n",
                __FILE__, __LINE__);
        assert(0);
      }
    }

    node_rbtree_t *element = (node_rbtree_t *)malloc(sizeof(node_rbtree_t));
    element->data = data;
    element->color = RBTREE_RED;
    element->parent = ptr;
    element->left = NULL;
    element->right = NULL;
    if (dir == -1) {
      ptr->left = element;
    } else if (dir == 1) {
      ptr->right = element;
    }

    if (ptr->color == RBTREE_BLACK)
      return; // only RED (children) - RED (parent) link causes an issue
    // TODO: Implement the rest of this function
  }
}

node_rbtree_t *rbteee_find(rbtree_t *tree, void *data);

int rbtree_erase(rbtree_t *tree, void *data);

void rbtree_cleanup(rbtree_t *tree);
