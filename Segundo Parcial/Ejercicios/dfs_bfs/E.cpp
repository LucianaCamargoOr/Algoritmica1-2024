#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)

#define output freopen("out.txt", "w", stdout)


vector<string> grafo;
// Vector de cadenas para representar el mapa bidimensional. Cada cadena es una fila del mapa.

int vx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int vy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
// Dos arreglos que indican movimientos permitidos en el mapa: 8 direcciones

int filas, columnas;


void dfs(int fila, int columna) {
// Esta función realiza una búsqueda en profundidad (DFS) desde una posición en el mapa.
    grafo[fila][columna] = '.'; // Marca la celda como visitada cambiando su contenido a '.'.

    // Recorre las 8 direcciones posibles para explorar celdas vecinas.
    for (int i = 0; i < 8; i++) {
        int nuevaFila = fila + vx[i]; // Nueva posición fila.
        int nuevaColumna = columna + vy[i]; // Nueva posición columna.
        
        // Verifica que la nueva posición esté dentro de los límites y que sea parte de una ameba (es decir, tiene '#').
        if (nuevaFila >= 0 && nuevaColumna >= 0 && nuevaFila < filas && nuevaColumna < columnas && grafo[nuevaFila][nuevaColumna] == '#') {
            dfs(nuevaFila, nuevaColumna); // Realiza DFS desde la nueva posición.
        }
    }
}

int main() {
    input; 

    // El bucle continúa mientras haya filas y columnas y al menos una no sea cero.
    while (cin >> filas >> columnas && (filas != 0 || columnas != 0)) {
        grafo.clear(); // Limpia el vector para leer un nuevo mapa.

        // Lee el mapa desde la entrada estándar, cada fila como una cadena.
        for (int i = 0; i < filas; i++) {
            string fila;
            cin >> fila;
            grafo.push_back(fila);
        }

        int amebas = 0; // Contador para el número de amebas.

        // Recorre todas las celdas del mapa.
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (grafo[i][j] == '#') { // Si la celda es negra ('#')...
                    dfs(i, j); // Inicia DFS para explorar toda la ameba.
                    amebas++; // Incrementa el contador de amebas.
                }
            }
        }

        cout << amebas << endl; // Imprime el número total de amebas en el mapa actual.
    }
}
