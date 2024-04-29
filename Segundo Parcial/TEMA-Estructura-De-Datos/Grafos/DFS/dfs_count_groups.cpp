#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

bool vis[10000];
// Un arreglo para rastrear si un nodo ha sido visitado durante la DFS. 

vector<int> grafo[10000];
// Un arreglo de vectores para representar un grafo. Cada índice corresponde a un nodo y el vector asociado contiene los nodos a los que está conectado.

void dfs(int nodoInicial) {
    stack<int> pilita; 
    pilita.push(nodoInicial); // Empuja el nodo inicial a la pila para comenzar la búsqueda.

    while (!pilita.empty()) { // Mientras haya elementos en la pila...
        int nodoActual = pilita.top(); // Toma el nodo en la parte superior de la pila.
        pilita.pop(); // Saca el nodo para procesarlo.

        if (!vis[nodoActual]) { // Si el nodo no ha sido visitado...
            vis[nodoActual] = true; // Se marca como visitado.

            for (int i = 0; i < grafo[nodoActual].size(); i++) { // Recorre todos los vecinos del nodo actual.
                int vecino = grafo[nodoActual][i]; // Obtiene un vecino.
                if (!vis[vecino]) { // Si el vecino no ha sido visitado...
                    pilita.push(vecino); // Lo empuja a la pila para visitarlo más adelante.
                }
            }
        }
    }
}

int main() {
    input; 
    int nroNodos, nroAristas; 
    cin >> nroNodos >> nroAristas; 

    // Lee cada arista y la agrega al grafo. Como el grafo es no dirigido, agrega cada conexión en ambos sentidos.
    for (int i = 0; i < nroAristas; i++) {
        int nodoInicio, nodoFinal;
        cin >> nodoInicio >> nodoFinal; // Lee los nodos conectados por cada arista.
        grafo[nodoInicio].push_back(nodoFinal); // Añade el nodo final como vecino del nodo inicial.
        grafo[nodoFinal].push_back(nodoInicio); // Añade el nodo inicial como vecino del nodo final.
    }

    int contGroups = 0; // Contador para el número de componentes conectados.
    // Recorre todos los nodos del grafo para iniciar una DFS si el nodo no ha sido visitado, indicando un nuevo componente.
    for (int i = 1; i <= nroNodos; i++) {
        if (!vis[i]) { // Si el nodo no ha sido visitado...
            contGroups++; // Incrementa el contador de componentes conectados.
            dfs(i); // Realiza una DFS desde este nodo para explorar todo el componente.
        }
    }

    cout << "Nro de Grupos es: " << contGroups << endl; // Imprime el número total de componentes conectados.
    return 0; 
}
