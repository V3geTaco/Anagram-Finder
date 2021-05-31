#include <iostream>
#include <fstream>
#include <string>


using namespace std;

#include "avl.hpp"
void preOrder(Node *root) {
    if(root != nullptr)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(int argc, char *argv[]) {
    string input_word;

    cout << "Input word: ";

    cin >> input_word;

    Node *root = nullptr;

    for (char c : input_word) {
        root = insert(root,  c);
    }

    ifstream fd("dict.txt");


    Node *dict_root = nullptr;
    
    /*for (string line; getline(fd, line);) {
        for (char &cline : line) {
            dict_root = insert(dict_root, cline);
        }

        if (identicalTrees(dict_root, root)) {
            cout << line << endl;
        }

        freeTree(dict_root);
    }*/


    fd.close();
    freeTree(root);

    return 0;
}