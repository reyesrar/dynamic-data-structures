#include <iostream>
#include "graph/graph.h"

using namespace std;

int main() {
    Graph<char> graph = Graph<char>();
    graph.addNode(1, 'A'); // Región A
    graph.addNode(2, 'B'); // Región B
    graph.addNode(3, 'C'); // Región C
    graph.addNode(4, 'D'); // Región D

    graph.addEdge(1, 2); // Puente 1
    graph.addEdge(2, 1); // Puente 1
    graph.addEdge(1, 2); // Puente 2
    graph.addEdge(2, 1); // Puente 2
    graph.addEdge(2, 3); // Puente 3
    graph.addEdge(3, 2); // Puente 3
    graph.addEdge(1, 3); // Puente 4
    graph.addEdge(3, 1); // Puente 4
    graph.addEdge(2, 4); // Puente 5
    graph.addEdge(4, 2); // Puente 5
    graph.addEdge(2, 4); // Puente 6
    graph.addEdge(4, 2); // Puente 6
    graph.addEdge(3, 4); // Puente 7
    graph.addEdge(4, 3); // Puente 7
    
    /*graph.addEdge(1, 4); // Puente 8
    graph.addEdge(4, 1); // Puente 8
    graph.addEdge(2, 3); // Puente 9
    graph.addEdge(3, 2); // Puente 9 */

    cout << "Verificando si el grafo tiene un ciclo euleriano..." << endl;
    graph.findEulerianCycle();
    graph.findEulerianPath();

    return 0;
}