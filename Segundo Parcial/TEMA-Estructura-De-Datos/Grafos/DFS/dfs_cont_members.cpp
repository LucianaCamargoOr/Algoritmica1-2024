#include<bits/stdc++.h>

using namespace std;// Permite utilizar elementos de la biblioteca estándar de C++ sin el prefijo "std::".

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)// Estos macros redirigen la entrada estándar y la salida estándar hacia y desde archivos específicos. En este caso, "in.txt" y "out.txt".

bool vis[10000];

vector<int> grafo[10000];

int members;
// Una variable para contar cuántos nodos pertenecen a un componente conectado.

void dfs(int nodoInicial) {
// Esta función implementa la búsqueda en profundidad (DFS) a partir de un nodo inicial.
    stack<int> pilita; // Se usa una pila para realizar la DFS.
    pilita.push(nodoInicial); // Empuja el nodo inicial a la pila.

    while (!pilita.empty()) { // Mientras la pila tenga elementos...
        int nodoActual = pilita.top(); // Obtiene el último elemento de la pila.
        pilita.pop(); // Elimina el último elemento de la pila, ya que va a procesarse.

        if (!vis[nodoActual]) { // Si el nodo actual no ha sido visitado...
            vis[nodoActual] = true; // Marca el nodo como visitado.
            members++; // Incrementa el contador de miembros del componente actual.

            for (int i = 0; i < grafo[nodoActual].size(); i++) { // Recorre todos los vecinos del nodo actual.
                int vecino = grafo[nodoActual][i]; // Obtiene un vecino del nodo actual.
                if (!vis[vecino]) { // Si el vecino no ha sido visitado...
                    pilita.push(vecino); // Lo empuja a la pila para ser procesado más tarde.
                }
            }
        }
    }
}

int main() {
    input; 
    int nroNodos, nroAristas;
    cin >> nroNodos >> nroAristas; // Lee el número de nodos y aristas del archivo de entrada.

    for (int i = 0; i < nroAristas; i++) {
        int nodoInicio, nodoFinal;
        cin >> nodoInicio >> nodoFinal; // Lee un par de nodos que representan una arista.
        grafo[nodoInicio].push_back(nodoFinal); // Agrega el nodo final como vecino del nodo inicial (arista dirigida).
        grafo[nodoFinal].push_back(nodoInicio); // También agrega el nodo inicial como vecino del nodo final (arista bidireccional).
    }

    int contGroups = 0; // Contador para el número de componentes conectados.
    for (int i = 1; i <= nroNodos; i++) { // Recorre todos los nodos del grafo.
        if (!vis[i]) { // Si el nodo no ha sido visitado...
            contGroups++; // Incrementa el contador de componentes.
            members = 0; // Resetea el contador de miembros para el nuevo componente.
            dfs(i); // Realiza DFS desde el nodo actual para explorar todo el componente.
            cout << "Del grupo " << i << " tiene " << members << " miembros" << endl; // Imprime el tamaño del componente.
        }
    }

    cout << "Número de Grupos es: " << contGroups << endl; // Imprime el número total de componentes conectados.
    return 0;
}
