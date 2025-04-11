# Problema
Königsberg (Actualmente Kaliningrado, Rusia) era una ciudad de la antigua Prusia Oriental. Esta ciudad es atravesada por el río Pregel, el cual llega un punto en el que rodea a la isla de Kneiphof para posteriormente separarse en dos ramas, de tal forma que se divide el terreno en 4 regiones. Cada una de las regiones se conectaban entre sí mediante 7 puentes. Dado el mapa de Königsberg, con el río Pregel dividiendo el plano en cuatro regiones distintas, que están unidas a través de los siete puentes, ¿es posible dar un paseo comenzando desde cualquiera de estas regiones, pasando por todos los puentes, recorriendo sólo una vez cada uno, y regresando al mismo punto de partida?

# Solución con Grafos
Para resolver este problema, se modela el mapa de Königsberg como un grafo no dirigido, donde:
- Cada región es representada como un nodo.
- Cada puente es representado como una arista entre dos nodos.
- Cada puente puede ser transitado en ambas direcciones.

El problema se reduce a determinar si el grafo tiene un ciclo euleriano, es decir, un recorrido que pase por todas las aristas exactamente una vez y regrese al punto de partida. Según la teoría de grafos, un grafo tiene un ciclo euleriano si y solo si:
1. Es conexo (todas las regiones están conectadas directa o indirectamente).
2. Todos los nodos tienen un grado par.

En este caso, se implementa un grafo en C++ para verificar estas condiciones y determinar si es posible realizar el recorrido solicitado.

# Implementación
El programa utiliza una clase `Graph` para representar el grafo. Se definen métodos para:
- Agregar nodos y aristas.
- Para conexiones no dirigidas, deben ser agregados los caminos en ambas direcciones.
- Verificar si el grafo tiene un ciclo y/o camino euleriano.
- Modificar datos (de ser requerido)

El resultado del análisis se imprime en la consola.

# Aplicacion
La solución del problema no sólo exige un camino euleriano, sino que además exige que forme un ciclo euleriano (Punto inicial = Punto final), de forma que el grado de los nodos debe de ser par. El grado de los nodos es 5,3,3,3. Por lo tanto, el problema no tiene solución.

Sin embargo, al eliminar cualquiera de los puentes, se nos queda un grafo con nodos de grado par excepto una pareja de grado impar. En este caso tenemos un camino euleriano. De igual forma, el problema no tendría la solución pedida ya que no forma un ciclo euleriano. 