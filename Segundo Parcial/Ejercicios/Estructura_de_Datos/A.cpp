#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

vector<string> grafo;
// Un vector de cadenas que representa el mapa bidimensional. Cada cadena es una fila del mapa.

int vx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int vy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
// Dos arreglos para definir los movimientos posibles en el mapa: 8 direcciones 

int filas, columnas;
// Variables para almacenar el número de filas y columnas del mapa.

void dfs(int fila, int columna) {
// Esta función realiza una búsqueda en profundidad (DFS) desde una celda específica.
    grafo[fila][columna] = '.'; // Marca la celda como visitada cambiando su contenido de '#' a '.'.

    // Recorre las 8 direcciones posibles para continuar la DFS.
    for (int i = 0; i < 8; i++) {
        int nuevaFila = fila + vx[i];
        int nuevaColumna = columna + vy[i];

        // Verifica que la nueva posición esté dentro de los límites del mapa y que sea una celda negra ('#').
        if (nuevaFila >= 0 && nuevaColumna >= 0 && nuevaFila < filas && nuevaColumna < columnas && grafo[nuevaFila][nuevaColumna] == '#') {
            dfs(nuevaFila, nuevaColumna); // Llama recursivamente a DFS para continuar explorando.
        }
    }
}

int main() {
    input;

    // Un bucle que se ejecuta mientras haya filas y columnas y al menos una de ellas no sea cero.
    while (cin >> filas >> columnas && (filas != 0 || columnas != 0)) {
        grafo.clear(); // Limpia el vector para leer un nuevo mapa.

        // Lee cada fila del mapa y la agrega al vector "grafo".
        for (int i = 0; i < filas; i++) {
            string fila; 
            cin >> fila;
            grafo.push_back(fila);
        }

        int amebas = 0; // Contador para las amebas encontradas.

        // Recorre todas las celdas del mapa.
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (grafo[i][j] == '#') { // Si la celda es negra ('#')...
                    dfs(i, j); // Inicia la DFS para explorar esta ameba.
                    amebas++; // Incrementa el contador de amebas.
                }
            }
        }

        cout << amebas << endl; // Imprime el número total de amebas encontradas.
    }
}
