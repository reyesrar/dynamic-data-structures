#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"

using namespace std;

template <class T>
class Graph {
private:
    Node<T>** nodes; // Array Dinamico de Nodos
    int nodeCount;   // Numero de Nodos
    int nodeCapacity; // Capacidad del Arreglo
    void resizeNodes(); // Redimensionar Array
    bool isConnected() const; // Verifica si el grafo es conexo
    void dfsVisit(int index, bool* visited) const; // Visita en profundidad
    bool hasEulerianPath() const; // Verifica si existe un camino euleriano
    void eulerianDFS(int index, bool* visitedEdges) const; // DFS para encontrar el camino euleriano

public:
    Graph(int initialCapacity = 2);
    ~Graph();
    void addNode(T id, T data = T());
    void addEdge(T fromId, T toId); //Agregar Arista
    Node<T>* findNode(T id) const;
    Node<T>** getNodes() const;
    int getNodeCount() const;
    void findEulerianPath() const; // Encuentra el camino euleriano
    void update(T id, T newData); // Actualiza el dato de un nodo segun su ID
    void findEulerianCycle() const; // Encuentra el ciclo euleriano
};

template <class T>
Graph<T>::Graph(int initialCapacity) : nodeCount(0), nodeCapacity(initialCapacity) {
    if (initialCapacity > 0) {
        nodes = new Node<T>*[nodeCapacity];
        for (int i = 0; i < nodeCapacity; ++i) nodes[i] = nullptr;
    } else nodes = nullptr;
}

template <class T>
Graph<T>::~Graph() {
    for (int i = 0; i < nodeCount; ++i) delete nodes[i];
    delete[] nodes;
}

template <class T>
void Graph<T>::addNode(T id, T data) {
    if (nodeCapacity == 0) {
        nodeCapacity = 2;
        nodes = new Node<T>*[nodeCapacity];
        for (int i = 0; i < nodeCapacity; ++i) nodes[i] = nullptr;
    }
    if (nodeCount == nodeCapacity) resizeNodes();
    nodes[nodeCount++] = new Node<T>(id, data);
}

template <class T>
void Graph<T>::addEdge(T fromId, T toId) {
    Node<T>* fromNode = findNode(fromId);
    Node<T>* toNode = findNode(toId);
    if (fromNode && toNode) fromNode->addAdjacent(toNode);
}

template <class T>
Node<T>* Graph<T>::findNode(T id) const {
    for (int i = 0; i < nodeCount; ++i) if (nodes[i]->getId() == id) return nodes[i];
    return nullptr;
}

template <class T>
Node<T>** Graph<T>::getNodes() const {
    return nodes;
}

template <class T>
int Graph<T>::getNodeCount() const {
    return nodeCount;
}

template <class T>
void Graph<T>::resizeNodes() {
    nodeCapacity *= 2;
    Node<T>** newNodes = new Node<T>*[nodeCapacity];
    for (int i = 0; i < nodeCount; ++i) newNodes[i] = nodes[i];
    for (int i = nodeCount; i < nodeCapacity; ++i) newNodes[i] = nullptr;
    delete[] nodes;
    nodes = newNodes;
}

template <class T>
bool Graph<T>::isConnected() const {
    if (nodeCount == 0) return true;

    bool* visited = new bool[nodeCount];
    for (int i = 0; i < nodeCount; ++i) visited[i] = false;

    // Encuentra el primer nodo con al menos un adyacente
    int startNode = -1;
    for (int i = 0; i < nodeCount; ++i) {
        if (nodes[i]->getAdjCount() > 0) {
            startNode = i;
            break;
        }
    }

    if (startNode == -1) { // Grafo vacio o sin aristas
        delete[] visited;
        return true;
    }

    dfsVisit(startNode, visited); // DFS desde el primer nodo adyacente

    for (int i = 0; i < nodeCount; ++i) { // Verifica si todos los nodos fueron visitados
        if (nodes[i]->getAdjCount() > 0 && !visited[i]) {
            delete[] visited;
            return false;
        }
    }

    delete[] visited;
    return true;
}

template <class T>
void Graph<T>::dfsVisit(int index, bool* visited) const {
    visited[index] = true;
    Node<T>** adjacents = nodes[index]->getAdjacents();
    int adjCount = nodes[index]->getAdjCount();

    for (int i = 0; i < adjCount; ++i) {
        for (int j = 0; j < nodeCount; ++j) if (adjacents[i] == nodes[j] && !visited[j]) dfsVisit(j, visited);
    }
}

template <class T>
bool Graph<T>::hasEulerianPath() const {
    if (!isConnected()) return false;

    int oddDegreeCount = 0;
    for (int i = 0; i < nodeCount; ++i) if (nodes[i]->getAdjCount() % 2 != 0) ++oddDegreeCount;

    return (oddDegreeCount == 0 || oddDegreeCount == 2);
}

template <class T>
void Graph<T>::findEulerianPath() const {
    if (!hasEulerianPath()) {
        cout << "No existe un camino euleriano en el grafo." << endl;
        return;
    }

    int startNode = 0;
    for (int i = 0; i < nodeCount; ++i) { // Encuentra un nodo de grado impar para comenzar el recorrido
        if (nodes[i]->getAdjCount() % 2 != 0) {
            startNode = i;
            break;
        }
    }

    // Recorrido DFS para encontrar el camino euleriano
    bool* visitedEdges = new bool[nodeCount * nodeCount];
    for (int i = 0; i < nodeCount * nodeCount; ++i) visitedEdges[i] = false;

    cout << "Camino Euleriano: ";
    eulerianDFS(startNode, visitedEdges);
    cout << std::endl;

    delete[] visitedEdges;
}

template <class T>
void Graph<T>::eulerianDFS(int index, bool* visitedEdges) const {
    Node<T>** adjacents = nodes[index]->getAdjacents();
    int adjCount = nodes[index]->getAdjCount();

    for (int i = 0; i < adjCount; ++i) {
        for (int j = 0; j < nodeCount; ++j) {
            if (adjacents[i] == nodes[j] && !visitedEdges[index * nodeCount + j]) {
                visitedEdges[index * nodeCount + j] = true;
                visitedEdges[j * nodeCount + index] = true;
                eulerianDFS(j, visitedEdges);
            }
        }
    }

    cout << nodes[index]->getData() << " ";
}

template <class T>
void Graph<T>::update(T id, T newData) {
    Node<T>* node = findNode(id);
    if (node) node->setData(newData);
    else cout << "Nodo con ID " << id << " no encontrado." << endl;
}

template <class T>
void Graph<T>::findEulerianCycle() const {
    if (!hasEulerianPath()) {
        cout << "No existe un ciclo euleriano en el grafo." << endl;
        return;
    }

    // Verifica que todos los nodos tengan grado par
    for (int i = 0; i < nodeCount; ++i) {
        if (nodes[i]->getAdjCount() % 2 != 0) {
            cout << "No existe un ciclo euleriano en el grafo." << endl;
            return;
        }
    }

    // Recorrido DFS para encontrar el ciclo euleriano
    bool* visitedEdges = new bool[nodeCount * nodeCount];
    for (int i = 0; i < nodeCount * nodeCount; ++i) visitedEdges[i] = false;

    cout << "Ciclo Euleriano: ";
    eulerianDFS(0, visitedEdges);
    cout << endl;

    delete[] visitedEdges;
}

#endif
