#include<iostream>
#include "./stack/stack.h"

using namespace std;

int main(){
    Stack<int> stack = Stack<int>(nullptr);
    stack.push(5);
    stack.push(6);
    stack.push(8);
    stack.push(1);
    stack.push(3);

    stack.invert();
    stack.print();
}