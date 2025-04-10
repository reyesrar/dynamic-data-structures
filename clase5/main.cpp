#include <iostream>
#include "binaryTree/binaryTree.h"

using namespace std;

int main(){
    Tree<int> tree = Tree<int>(nullptr);
    tree.insert(8);
    tree.insert(4);
    tree.insert(10);
    tree.insert(2);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);

    tree.search(100, PREORDER);
    cout << endl;
    tree.search(100, INORDER);
    cout << endl;
    tree.search(100, POSTORDER);
    return 0;
    
}