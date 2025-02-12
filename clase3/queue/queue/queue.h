#pragma once
#include <iostream>
#include "../node/node.h"

using namespace std;

template <class T>
class Queue{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
    public:
        Queue(Node<T>*);
        void push(T);
        T pop();
        void print();
        
};

template <class T>
Queue<T>::Queue(Node<T>* node){
    this->head = node;
    this->tail = head;
}

template<class T>
void Queue<T>::push(T data){
    Node<T>* newNode = new Node<T>(data);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        tail->setNext(newNode);
        tail = newNode;
    }
}

template<class T>
T Queue<T>::pop(){
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
void Queue<T>::print(){
    while(head != nullptr) pop();
}

/* template <class T>
void List<T>::insert(T data){
    Node<T>* newNode = new Node<T>(data);

    if(head == nullptr) head = newNode;
    else if(data < head->getData()){
        newNode->setNext(head);
        head = newNode;
    } else {
        Node<T>* actual = head;
        while(actual->getNext() != nullptr && actual->getNext()->getData() < data) actual = actual->getNext();
        newNode->setNext(actual->getNext());
        actual->setNext(newNode);
    }
        
}

template <class T>
bool List<T>::deleteNode(T data){
    Node<T>* toDelete = head;
    Node<T>* prev = nullptr;
    while(toDelete != nullptr && toDelete->getData() != data){
        prev = toDelete;
        toDelete = toDelete->getNext();
    }
    if(toDelete == nullptr) return false;
    if(prev == nullptr) head = toDelete->getNext();
    else prev->setNext(toDelete->getNext());
    delete toDelete;
    return true;
}

template <class T>
void List<T>::print(){
    Node<T>* actual = head;
    while(actual != nullptr){
        actual->print();
        actual = actual->getNext();
    }
} */