#pragma once
#include <iostream>
#include "../node/node.h"

using namespace std;

template <class T>
class DLList{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
    public:
        DLList(Node<T>*);
        void insert(T);
        bool deleteNode(T);
        void print();
        void printReverse();
        void update(T, T);
        
};

template <class T>
DLList<T>::DLList(Node<T>* node){
    this->head = node;
    this->tail = node;
}

template <class T>
void DLList<T>::insert(T data){
    Node<T>* newNode = new Node<T>(data);

    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    } else if(data < head->getData()){
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    } else if(data > tail->getData()){
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    } else {
        Node<T>* actual = head;
        while(actual->getNext() != nullptr && actual->getNext()->getData() < data) actual = actual->getNext();
        newNode->setNext(actual->getNext());
        if(actual->getNext() != nullptr) actual->getNext()->setPrev(newNode);
        else tail = newNode;
        actual->setNext(newNode);
        newNode->setPrev(actual);
    }
        
}

template <class T>
bool DLList<T>::deleteNode(T data){
    Node<T>* toDelete = head;
    while(toDelete != nullptr && toDelete->getData() != data) toDelete = toDelete->getNext();
    if(toDelete == nullptr) return false;
    if(toDelete->getPrev() != nullptr) toDelete->getPrev()->setNext(toDelete->getNext());
    else head = toDelete->getNext();
    if(toDelete->getNext() != nullptr) toDelete->getNext()->setPrev(toDelete->getPrev());
    else tail = toDelete->getPrev();
    delete toDelete;
    return true;
}

template <class T>
void DLList<T>::print(){
    Node<T>* actual = head;
    while(actual != nullptr){
        actual->print();
        actual = actual->getNext();
    }
}

template <class T>
void DLList<T>::printReverse(){
    Node<T>* actual = tail;
    while(actual != nullptr){
        actual->print();
        actual = actual->getPrev();
    }
}

template <class T>
void DLList<T>::update(T oldData, T newData){
    if (deleteNode(oldData)) {
        insert(newData);
    }
}