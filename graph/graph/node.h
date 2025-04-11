#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
private:
    T id;
    T data;
    Node<T>** adjacents; // Arreglo Dinamico de Nodos Adyacentes
    int adjCount; // Numero de Nodos Adyacentes
    int adjCapacity; // Capacidad del Array
    void resizeAdjacents(); // Redimensionar Array

public:
    Node(T id, T data = T(), int initialCapacity = 2);
    ~Node();
    T getId() const;
    T getData() const;
    void setData(T data);
    void addAdjacent(Node<T>* node);
    Node<T>** getAdjacents() const;
    int getAdjCount() const;
    
};

template <class T>
Node<T>::Node(T id, T data, int initialCapacity) : id(id), data(data), adjCount(0), adjCapacity(initialCapacity) {
    adjacents = new Node<T>*[adjCapacity];
}

template <class T>
Node<T>::~Node() {
    delete[] adjacents;
}

template <class T>
T Node<T>::getId() const {
    return id;
}

template <class T>
T Node<T>::getData() const {
    return data;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
void Node<T>::addAdjacent(Node<T>* node) {
    if (adjCount == adjCapacity) resizeAdjacents();
    adjacents[adjCount++] = node;
}

template <class T>
Node<T>** Node<T>::getAdjacents() const {
    return adjacents;
}

template <class T>
int Node<T>::getAdjCount() const {
    return adjCount;
}

template <class T>
void Node<T>::resizeAdjacents() {
    adjCapacity *= 2;
    Node<T>** newAdjacents = new Node<T>*[adjCapacity];
    for (int i = 0; i < adjCount; ++i) newAdjacents[i] = adjacents[i];
    delete[] adjacents;
    adjacents = newAdjacents;
}

#endif
