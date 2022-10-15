//
//  tree.c
//  CCode
//
//  Created by abedalkareem omreyh on 15/10/2022.
//

#include "tree.h"
#include <stdlib.h>

struct treeNode {
  int data;
  struct treeNode *left;
  struct treeNode *right;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value) {
  if (*treePtr == NULL) {
    *treePtr = malloc(sizeof(TreeNode));

    if (*treePtr != NULL) {
      (*treePtr)->data = value;
      (*treePtr)->right = NULL;
      (*treePtr)->left = NULL;
    }
  } else {
    if (value < (*treePtr)->data) {
      insertNode(&((*treePtr)->left), value);
    } else if (value > (*treePtr)->data) {
      insertNode(&((*treePtr)->right), value);
    }
  }
}

void inOrder(TreeNodePtr treePtr) {
  if (treePtr != NULL) {
    inOrder(treePtr->left);
    printf("%3d", treePtr->data);
    inOrder(treePtr->right);
  }
}

void preOrder(TreeNodePtr treePtr) {
  if (treePtr != NULL) {
    printf("%3d", treePtr->data);
    preOrder(treePtr->left);
    preOrder(treePtr->right);
  }
}

void postOrder(TreeNodePtr treePtr) {
  if (treePtr != NULL) {
    postOrder(treePtr->left);
    postOrder(treePtr->right);
    printf("%3d", treePtr->data);
  }
}
