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
        void printByAge();
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
    return nodeData;
}

template<class T>
void Queue<T>::print(){
    T nodeData;
    while(head != nullptr){
        pop();
        cout<<nodeData<<endl;
    }
}

template<class T>
void Queue<T>::printByAge() {
    if (head == nullptr) return;

    Node<T>* actual = head;
    while (actual != nullptr) {
        Node<T>* youngest = actual;
        Node<T>* nextNode = actual->getNext();

        while (nextNode != nullptr) {
            if (nextNode->getData().age < youngest->getData().age) youngest = nextNode;
            nextNode = nextNode->getNext();
        }

        cout << "Nombre: " << youngest->getData().name << ", Edad: " << youngest->getData().age << ", Peso: " << youngest->getData().weight << endl;

        T temp = actual->getData();
        actual->setData(youngest->getData());
        youngest->setData(temp);
        actual = actual->getNext();
    }
}

