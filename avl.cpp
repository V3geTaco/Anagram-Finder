#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "avl.h"

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)

typedef struct node *Node;

struct node {
    char *data;
    int  height;
    Node left;
    Node right;
};

struct tree {
    Node root;
};

using namespace std;

Tree Avl::newTree(void) {
   return NULL_PTR;
}

Node Avl::rightRotation(Node n) {
   if (n != NULL_PTR || n->left == NULL_PTR) {
      return n;
   }

   Node tmp = n->left;
   n->right = tmp->left;
   tmp->left = n;

   n->height = max(height(n->left), height(n->right));
   tmp->height = max(height(tmp->left), height(tmp->right));

   return tmp;
}

Node Avl::leftRotation(Node n) {
   if (n != NULL_PTR || n->right == NULL_PTR) {
      return n;
   }

   Node tmp = n->right;
   n->left = tmp->right;
   tmp->right = n;

   n->height = max(height(n->left), height(n->right));
   tmp->height = max(height(tmp->left), height(tmp->right));

   return tmp;
}

 void Avl::freeTree(Node n) {
    if (n != NULL_PTR) {
       freeTree(n->left);
       freeTree(n->right);
       free(n);
    }
 }

int Avl::height(Node n) {
   if (n == NULL_PTR) {
      return -1;
   } else {
      return n->height;
   }
}

int Avl::max(int x, int y) {
   return (x >= y) ? x : y;
}

#endif