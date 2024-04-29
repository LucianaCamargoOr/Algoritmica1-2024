#include<bits/stdc++.h> // Incluye todas las librerías estándar de C++
using namespace std;


#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)


bool vis[10000]; 
// Un arreglo para llevar un registro de los nodos que han sido visitados en el BFS. 
// Se inicializa con un tamaño de 10,000, lo que permite rastrear si un nodo ya ha 
//sido visitado.

vector<int> grafo[10000];
// Un arreglo de vectores para representar el grafo. 
//Cada índice representa un nodo y el vector asociado almacena sus vecinos.

int niveles[10000];
// Un arreglo para almacenar el nivel de cada nodo,osea 
//la distancia en términos de aristas desde el nodo inicial.

void bfs(int nodoInicial) {
    queue<int> colita; // Cola para la implementación de BFS.
    colita.push(nodoInicial); // Añade el nodo inicial a la cola.
    niveles[nodoInicial] = 0; // Asigna el nivel cero al nodo inicial.

    while (!colita.empty()) { // Mientras la cola no esté vacía...
        int nodoActual = colita.front(); // Obtiene el primer elemento de la cola.
        colita.pop(); // Elimina el primer elemento de la cola, porque está siendo procesado.

        if (!vis[nodoActual]) { // Si el nodo actual no ha sido visitado...
            vis[nodoActual] = true; // Marcarlo como visitado.
            // Recorre todos los vecinos del nodo actual.
            for (int i = 0; i < grafo[nodoActual].size(); i++) {
                int amigo = grafo[nodoActual][i]; // Obtiene un vecino del nodo actual.
                niveles[amigo] = niveles[nodoActual] + 1; // Asigna el nivel al vecino, incrementándolo por 1 respecto al nodo actual.
                
                if (!vis[amigo]) { // Si el vecino no ha sido visitado...
                    colita.push(amigo); // Añade el vecino a la cola para procesarlo después.
                }
            }
        }
    }
}

int main() {
    input; 
    int nodos, aristas; 
    cin >> nodos >> aristas; 

    for (int i = 0; i < aristas; i++) {
        int nodoInicial, nodoFinal;
        cin >> nodoInicial >> nodoFinal; 
        grafo[nodoInicial].push_back(nodoFinal); // Añade el nodo final como vecino del nodo inicial.
    }

    int S, T; // dos nodos: el inicial y el objetivo.
    cin >> S >> T; 
    bfs(S); // Ejecuta el BFS desde el nodo S.

    if (vis[T]) { // Si el nodo T fue visitado durante el BFS...
        cout << "Si lo podría conocer" << endl; // Significa que hay un camino desde S hasta T.
    } else {
        cout << "No lo podría conocer" << endl; // No se encontró un camino entre S y T.
    }
}
