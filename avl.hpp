#ifndef AVL_H
#define AVL_H

class Node {
    public:
        int    height;
        Node   *left;
        Node   *right;
        char   data;
};


Node *newNode(char word);
Node *rightRotation(Node *n);
Node *leftRotation(Node *n);
Node *insert(Node *t, char val);
void freeTree(Node *n);

bool identicalTrees(Node *n1, Node *n2);

#endif