#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

bool vis[10000];


vector<int> grafo[10000];


void dfs(int nodoInicial) {
// Esta función realiza una búsqueda en profundidad (DFS) desde un nodo específico para explorar todos los nodos conectados.
    stack<int> pilita; // Se utiliza una pila para gestionar la DFS.
    pilita.push(nodoInicial); // Añade el nodo inicial a la pila para comenzar la búsqueda.

    while (!pilita.empty()) { // Mientras haya elementos en la pila...
        int nodoActual = pilita.top(); // Obtiene el elemento superior de la pila.
        pilita.pop(); // Elimina el elemento superior de la pila, ya que va a procesarse.

        if (!vis[nodoActual]) { // Si el nodo actual no ha sido visitado...
            vis[nodoActual] = true; // Se marca como visitado.

            // Recorre todos los vecinos del nodo actual.
            for (int i = 0; i < grafo[nodoActual].size(); i++) {
                int amigo = grafo[nodoActual][i]; // Obtiene un vecino del nodo actual.
                
                if (!vis[amigo]) { // Si el vecino no ha sido visitado...
                    pilita.push(amigo); // Lo añade a la pila para procesarlo más tarde.
                }
            }
        }
    }
}

int main() {
    input; 
    int nodos, aristas; 
    cin >> nodos >> aristas; 

    // Lee cada arista y la agrega al grafo, creando la estructura del grafo.
    for (int i = 0; i < aristas; i++) {
        int nodoInicial, nodoFinal; 
        cin >> nodoInicial >> nodoFinal; 
        grafo[nodoInicial].push_back(nodoFinal); // Añade el nodo final como vecino del nodo inicial.
    }

    // Lee dos nodos: el nodo de inicio y el nodo de destino.
    int S, T;
    cin >> S >> T; 

    // Ejecuta la DFS desde el nodo S para ver si puede llegar al nodo T.
    dfs(S);

    // Si el nodo T fue visitado durante la DFS...
    if (vis[T]) {
        cout << "Si lo podría conocer" << endl; // Indica que hay un camino entre S y T.
    } else {
        cout << "No lo podría conocer" << endl; // Indica que no hay camino entre S y T.
    }
}
