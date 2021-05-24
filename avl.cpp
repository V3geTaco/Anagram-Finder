#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "avl.hpp"

/*static function declares*/
static int height(Node n);
static int max(int x, int y);
static int getbalancefac(Node n);

/*avl tree class methods*/
Tree Avl::newTree(void) {
   Tree t = new struct tree;
   t->root = NULL;

   return t;
}

Node Avl::newNode(char word) {
   Node n = new struct node;

   n->data = word;
   n->left = nullptr;
   n->right = nullptr;
   n->height = 1;
   return n;
}

Node Avl::rightRotation(Node n) {
   if (n != nullptr || n->left == nullptr) {
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
   if (n != nullptr || n->right == nullptr) {
      return n;
   }

   Node tmp = n->right;
   n->left = tmp->right;
   tmp->right = n;

   n->height = max(height(n->left), height(n->right));
   tmp->height = max(height(tmp->left), height(tmp->right));

   return tmp;
}

void Avl::insert(Tree t, char val) {
   Node node = nullptr;
   Node next = nullptr;
   Node last = nullptr;

   if (t->root == nullptr) {
      Node n = newNode(val);
      t->root = n;
   } else {
      next = t->root;
      last = nullptr;

      while (next != nullptr) {
         last = next;

         if (val < next->data) {
            next = next->left;
            
         } else if (val > next->data) {
            next = next->right;

         } else if (val == next->data) {
            next = next->left;

         }

         node = newNode(val);

         if (val < last->data) last->left = node;
         if (val > last->data) last->right = node;

      }
   }
}

 void Avl::freeTree(Node n) {
    if (n != nullptr) {
       freeTree(n->left);
       freeTree(n->right);
       delete n;
    }
 }

/*static functions*/
static int getbalancefac(Node n) {
   if (n == nullptr) return 0;

   return height(n->left) - height(n->right);
}

static int height(Node n) {
   if (n == nullptr) {
      return -1;
   } else {
      return n->height;
   }
}

static int max(int x, int y) {
   return (x >= y) ? x : y;
}
