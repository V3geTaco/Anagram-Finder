#ifndef AVL_H
#define AVL_H

typedef struct tree *Tree;

class Avl {
    private:
        static int height(Node n);
        static int max(int x, int y);
    protected:

    public:
        Tree newTree(void);
        Node rightRotation(Node n);
        Node leftRotation(Node n);
        void freeTree(Node n);
};



#endif