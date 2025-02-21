#include <iostream>
#include "doubleLinkedList/doubleLinked.h"

using namespace std;

int main(){
    DLList<int> list = DLList<int>(nullptr);
    list.insert(10);
    list.insert(8);
    list.insert(12);
    list.insert(9);
    list.insert(5);
    list.insert(4);
    list.insert(11);

    list.update(11, 15);
    list.update(4, 20);
    list.deleteNode(8);
    list.deleteNode(10);
    list.deleteNode(5);

    list.printReverse();
}