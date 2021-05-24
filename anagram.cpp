#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "avl.hpp"

int main(int argc, char *argv[]) {
    string input_word;

    cout << "Input word: ";

    cin >> input_word;

    Avl avlinput;

    Tree inputtree = avlinput.newTree();
    for (char &c : input_word) {
        avlinput.insert(inputtree, c);
    }

    return 0;
}