#include <iostream>
#include "binaryTree/binaryTree.h"

using namespace std;

int main(){
    Tree<int> tree = Tree<int>(nullptr);
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.insert(9);

    tree.remove(10);
    cout << endl;
    tree.search(10, PREORDER);
    cout << endl;
    tree.search(10, INORDER);
    cout << endl;
    tree.search(10, POSTORDER);
    cout << endl;

    tree.update(9, 8);
    cout << endl;
    tree.search(9, PREORDER);
    cout << endl;
    tree.search(8, PREORDER);
    return 0;
    
}