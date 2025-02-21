#pragma once
#include <iostream>
#include "../node/node.h"

using namespace std;

template <class T>
class CircularList {
    private:
        Node<T>* head = nullptr;
    public:
        CircularList(Node<T>*);
        void insert(T);
        bool deleteNode(T);
        void print();
        void update(T, T);
};

template <class T>
CircularList<T>::CircularList(Node<T>* node) {
    this->head = node;
    if (node != nullptr) node->setNext(node);
}

template <class T>
void CircularList<T>::insert(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr) {
        head = newNode;
        head->setNext(head);
    } else if (data < head->getData()) {
        Node<T>* tail = head;
        while (tail->getNext() != head) tail = tail->getNext();
        newNode->setNext(head);
        head = newNode;
        tail->setNext(head);
    } else {
        Node<T>* actual = head;
        while (actual->getNext() != head && actual->getNext()->getData() < data) actual = actual->getNext();
        newNode->setNext(actual->getNext());
        actual->setNext(newNode);
    }
}

template <class T>
bool CircularList<T>::deleteNode(T data) {
    if (head == nullptr) return false;

    Node<T>* toDelete = head;
    Node<T>* prev = nullptr;

    do {
        if (toDelete->getData() == data) break;
        prev = toDelete;
        toDelete = toDelete->getNext();
    } while (toDelete != head);

    if (toDelete->getData() != data) return false;

    if (prev == nullptr) {
        if (head->getNext() == head) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* tail = head;
            while (tail->getNext() != head) tail = tail->getNext();
            head = head->getNext();
            tail->setNext(head);
            delete toDelete;
        }
    } else {
        prev->setNext(toDelete->getNext());
        delete toDelete;
    }
    return true;
}

template <class T>
void CircularList<T>::print() {
    if (head == nullptr) return;

    Node<T>* actual = head;
    do {
        actual->print();
        actual = actual->getNext();
    } while (actual != head);
}

template <class T>
void CircularList<T>::update(T oldData, T newData) {
    if (deleteNode(oldData)) insert(newData);
}