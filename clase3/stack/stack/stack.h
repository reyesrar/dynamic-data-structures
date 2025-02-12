#pragma once
#include <iostream>
#include "../node/node.h"

using namespace std;

template <class T>
class Stack{
    private:
        Node<T>* head = nullptr;
    public:
        Stack(Node<T>*);
        void push(T);
        T pop();
        void print();
        
        
};

template <class T>
Stack<T>::Stack(Node<T>* node){
    this->head = node;
}

template<class T>
void Stack<T>::push(T data){
    Node<T>* newNode = new Node<T>(data);
    if(head == nullptr) head = newNode;
    else{
        newNode->setNext(head);
        head = newNode;
    }
    
}

template<class T>
T Stack<T>::pop(){
    T nodeData;
    if(head == nullptr) return nodeData;
    Node<T>* toPop = head;
    head = head->getNext();
    nodeData = toPop->getData();
    delete toPop;
    cout<<nodeData<<endl;
    return nodeData;
}

template<class T>
void Stack<T>::print(){
    while(head != nullptr) pop();
}