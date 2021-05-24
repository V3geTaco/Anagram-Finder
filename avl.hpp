#ifndef AVL_H
#define AVL_H

struct tree {
    Node root;
};
typedef struct tree *Tree;

struct node {
    int    height;
    Node   left;
    Node   right;
    char   data;
};
typedef struct node *Node;

class Avl {
    public:
        Tree newTree(void);
        Node newNode(char word);
        Node rightRotation(Node n);
        Node leftRotation(Node n);
        void insert(Tree t, char val);
        void freeTree(Node n);
};



#endif