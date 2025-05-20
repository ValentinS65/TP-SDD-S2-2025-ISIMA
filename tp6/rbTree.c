#include <stdio.h>
#include <stdlib.h>
#include "rbTree.h"

// Create a red-black tree
struct rbNode * rbtCreateNode(int data) {
    // TODO : question 1
}

// Insert an node
struct rbNode * rbtInsert(struct rbNode * root, int data) {
  struct rbNode *stack[100], *ptr, *newnode, *xPtr, *yPtr;
  int dir[100], ht = 0, index;
  ptr = root;
  if (!root) {
    root = rbtCreateNode(data);
    return root;
  }

  stack[ht] = root;
  dir[ht++] = 0;
  while (ptr != NULL) {
    if (ptr->data == data) {
      printf("Duplicates Not Allowed!!\n");
      return root;
    }
    index = (data - ptr->data) > 0 ? 1 : 0;
    stack[ht] = ptr;
    ptr = ptr->link[index];
    dir[ht++] = index;
  }
  stack[ht - 1]->link[index] = newnode = rbtCreateNode(data);
  while ((ht >= 3) && (stack[ht - 1]->color == RED)) {
      // TODO : question 2 (vérification et correction sur l'arbre rouge-noir)
  }
  root->color = BLACK;
  return root;
}

// Delete a node
struct rbNode * rbtDelete(struct rbNode * root, int data) {
  struct rbNode *stack[100], *ptr, *xPtr, *yPtr;
  struct rbNode *pPtr, *qPtr, *rPtr;
  int dir[100], ht = 0, diff, i;
  enum nodeColor color;

  if (!root) {
    printf("Tree not available\n");
    return root;
  }

  ptr = root;
  while (ptr != NULL) {
    if ((data - ptr->data) == 0)
      break;
    diff = (data - ptr->data) > 0 ? 1 : 0;
    stack[ht] = ptr;
    dir[ht++] = diff;
    ptr = ptr->link[diff];
  }

  if (ptr->link[1] == NULL) {
      // TODO : question 3 (Plusieurs conditions de vérification et correction)
  } else {
    xPtr = ptr->link[1];
    if (xPtr->link[0] == NULL) {
        // TODO : question 3 (Plusieurs conditions de vérification et correction)
    } else {
        // TODO : question 3 (Plusieurs conditions de vérification et correction)
    }
  }

  if (ht < 1)
    return root;

  if (ptr->color == BLACK) {
      // TODO : question 3 (Plusieurs conditions de vérification et correction)
  }
  return root;
}

// Print the inorder traversal of the tree
void rbtDisplay(struct rbNode *node) {
    // TODO : question 4
}
