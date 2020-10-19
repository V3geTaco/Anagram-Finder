#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <string.h>

#include "avl.h"

struct Node {
   int  data;
   int  height;
   Tree left, right;
};

struct Tree {
   Node root;
};

using namespace std;

Tree Avl::newTree(void) {
   return NULL;
}

Tree Avl::rightRotation(Tree n) {
   if (n != NULL || n->left == NULL) {
      return n;
   }

   Tree tmp = n->left;
   n->right = tmp->left;
   tmp->left = n;

   n->height = max(height(n->left), height(n->right));
   tmp->height = max(height(tmp->left), height(tmp->right));

   return tmp;
}

Tree Avl::leftRotation(Tree n) {
    // similar to right rotation
    // not finished
    return NULL;
}

 void Avl::freeTree(Tree t) {
    if (t != NULL) {
       freeTree(t->left);
       freeTree(t->right);
       free(t);
    }
 }

static int Avl::height() {

}

static int Avl::max(int x, int y) {
   return (x >= y) ? x : y;
}