#ifndef AVL_H
#define AVL_H

typedef struct Node *Tree;

class Avl {
    private:
        static int height(Tree n);
        static int max(int x, int y);
    protected:

    public:
        Tree newTree(void);
        void rightRotation(Tree n);
        void leftRotation(Tree n);
        void freeTree(Tree t);
};



#endif