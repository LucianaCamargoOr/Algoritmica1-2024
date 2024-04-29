#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

vector<string> grafo(1000);
// Este vector de cadenas de caracteres representará el mapa bidimensional. Cada cadena es una fila del mapa.

int vis[1000][1000];
// Una matriz para rastrear las posiciones visitadas en el mapa. 

int vx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int vy[] = {0, 0, 1, -1, 1, -1, 1, -1};
// Estas dos matrices de enteros representan los movimientos permitidos en el mapa.

int dfs(int fila, int columna) {
// Esta función realiza una búsqueda en profundidad (DFS) desde una posición dada en el mapa.
    vis[fila][columna] = true; // Marca la posición actual como visitada.
    // Recorre todos los movimientos posibles (ocho direcciones).
    for (int i = 0; i < 8; i++) {
        int nuevaFila = fila + vx[i]; // Calcula la nueva fila basándose en el movimiento actual.
        int nuevaColumna = columna + vy[i]; // Calcula la nueva columna.
        
        // Verifica que la nueva posición esté dentro del rango permitido y que sea parte de una isla (es decir, es "1").
        if (nuevaFila >= 0 && nuevaFila <= 3 
            && nuevaColumna >= 0 && nuevaColumna <= 4 
            && grafo[nuevaFila][nuevaColumna] == '1') 
        {
            if (!vis[nuevaFila][nuevaColumna]) { // Si la posición no ha sido visitada...
                dfs(nuevaFila, nuevaColumna); // Realiza DFS desde la nueva posición.
            }
        }
    }
}

int main() {
    int filas, columnas; 
    cin >> filas >> columnas; 
    memset(vis, 0, sizeof(vis)); // Inicializa la matriz de visitados a cero.
    
    // Lee el mapa desde la entrada estándar. Cada fila se almacena como una cadena en el vector "grafo".
    for (int i = 0; i < filas; i++) {
        cin >> grafo[i]; 
    }

    int contIslas = 0; // Contador para el número de islas.
    // Recorre todas las posiciones del mapa.
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // Si la posición actual es parte de una isla y no ha sido visitada...
            if (!vis[i][j] && grafo[i][j] == '1') {
                dfs(i, j); // Realiza DFS para marcar toda la isla.
                contIslas++; // Incrementa el contador de islas.
            }
        }
    }

    cout << "Número de islas es: " << contIslas << endl; 
    return 0;
}
