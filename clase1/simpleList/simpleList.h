#pragma once
#include <iostream>
#include "../node/node.h"

using namespace std;

template <class T>
class List{
    private:
        Node<T>* head = nullptr;
    public:
        List(Node<T>*);
        void insert(T);
        bool deleteNode(T);
        void print();
        void update(T, T);
};

template <class T>
List<T>::List(Node<T>* node){
    this->head = node;
}

template <class T>
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
}

template <class T>
void List<T>::update(T oldData, T newData){
    if (deleteNode(oldData)) insert(newData);
}