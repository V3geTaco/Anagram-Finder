#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "avl.hpp"

/*static function declares*/
static int height(Node *n);
static int max(int x, int y);
static int getbalancefac(Node *n);

/*avl tree class methods*/

Node *newNode(char word) {
   Node *n = new Node();

   n->data = word;
   n->left = nullptr;
   n->right = nullptr;
   n->height = 1;
   return n;
}

Node *rightRotation(Node *n) {
   if (n != nullptr || n->left == nullptr) {
      return n;
   }

   Node *tmp = n->left;
   n->right = tmp->left;
   tmp->left = n;

   n->height = max(height(n->left), height(n->right));
   tmp->height = max(height(tmp->left), height(tmp->right));

   return tmp;
}

Node *leftRotation(Node *n) {
   if (n != nullptr || n->right == nullptr) {
      return n;
   }

   Node *tmp = n->right;
   n->left = tmp->right;
   tmp->right = n;

   n->height = max(height(n->left), height(n->right));
   tmp->height = max(height(tmp->left), height(tmp->right));

   return tmp;
}

Node *insert(Node *t, char val) {
   Node *n = t;

   if (n == nullptr) return newNode(val);

   if (val < n->data) {
      n->left = insert(n->left, val);
   } else if (val > n->data) {
      n->right = insert(n->right, val);
   } else {
      n->left = insert(n->left, val);
   }

   n->height = 1 + max(height(n->left), height(n->right));

   int bal = getbalancefac(n);

   if (bal > 1 && val < n->left->data) return rightRotation(n);
   if (bal > 1 && val > n->left->data) {
      n->left = leftRotation(n->left);
      return rightRotation(n);
   }

   if (bal < -1 && val > n->right->data) return leftRotation(n);
   if (bal < -1 && val < n->right->data) {
      n->right = rightRotation(n->right);
      return leftRotation(n);
   }

   return n;
}

void freeTree(Node *n) {
   if (n != nullptr) {
      freeTree(n->left);
      freeTree(n->right);
      delete n;
   }
}

bool identicalTrees(Node *n1, Node *n2) {
   if (n1 == nullptr && n2 == nullptr) return true;

   if (n1 != nullptr && n2 != nullptr) {
      return (n1->data == n2->data && identicalTrees(n1->left, n2->left) && identicalTrees(n1->right, n2->right));
   }

   return false;
}


/*static functions*/
static int getbalancefac(Node *n) {
   if (n == nullptr) return 0;

   return height(n->left) - height(n->right);
}

static int height(Node *n) {
   if (n == nullptr) {
      return -1;
   } else {
      return n->height;
   }
}

static int max(int x, int y) {
   return (x >= y) ? x : y;
}
