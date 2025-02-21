#pragma once
#include <iostream>
#include "../node/node.h"

using namespace std;

template <class T>
class CircularDLList {
    private:
        Node<T>* head = nullptr;
    public:
        CircularDLList(Node<T>*);
        void insert(T);
        bool deleteNode(T);
        void print();
        void printReverse();
        void update(T, T);
};

template <class T>
CircularDLList<T>::CircularDLList(Node<T>* node) {
    this->head = node;
    if (node != nullptr) {
        node->setNext(node);
        node->setPrev(node);
    }
}

template <class T>
void CircularDLList<T>::insert(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr) {
        head = newNode;
        head->setNext(head);
        head->setPrev(head);
    } else if (data < head->getData()) {
        Node<T>* tail = head->getPrev();
        newNode->setNext(head);
        newNode->setPrev(tail);
        head->setPrev(newNode);
        tail->setNext(newNode);
        head = newNode;
    } else {
        Node<T>* actual = head;
        while (actual->getNext() != head && actual->getNext()->getData() < data) actual = actual->getNext();
        newNode->setNext(actual->getNext());
        newNode->setPrev(actual);
        actual->getNext()->setPrev(newNode);
        actual->setNext(newNode);
    }
}

template <class T>
bool CircularDLList<T>::deleteNode(T data) {
    if (head == nullptr) return false;

    Node<T>* toDelete = head;

    do {
        if (toDelete->getData() == data) break;
        toDelete = toDelete->getNext();
    } while (toDelete != head);

    if (toDelete->getData() != data) return false;

    if (toDelete == head) {
        if (head->getNext() == head) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* tail = head->getPrev();
            head = head->getNext();
            head->setPrev(tail);
            tail->setNext(head);
            delete toDelete;
        }
    } else {
        toDelete->getPrev()->setNext(toDelete->getNext());
        toDelete->getNext()->setPrev(toDelete->getPrev());
        delete toDelete;
    }
    return true;
}

template <class T>
void CircularDLList<T>::print() {
    if (head == nullptr) return;

    Node<T>* actual = head;
    do {
        actual->print();
        actual = actual->getNext();
    } while (actual != head);
}

template <class T>
void CircularDLList<T>::printReverse() {
    if (head == nullptr) return;

    Node<T>* actual = head->getPrev();
    do {
        actual->print();
        actual = actual->getPrev();
    } while (actual != head->getPrev());
}

template <class T>
void CircularDLList<T>::update(T oldData, T newData) {
    if (deleteNode(oldData)) insert(newData);
}