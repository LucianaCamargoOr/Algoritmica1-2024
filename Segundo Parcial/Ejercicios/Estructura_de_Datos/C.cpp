#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

int main() {
    input; 
    output; 
    
    int s, b; // Variables para el número de soldados y el número de eliminaciones.
    while (cin >> s >> b && s && b) {
        vector<int> soldiers(s); // Crea un vector para representar a los soldados.
        // Inicializa el vector de soldados con valores del 1 al s.
        for (int i = 0, j = 1; i < s; i++, j++) {
            soldiers[i] = j;
        }
        
        int leftOld = s; // Variable para el soldado más a la izquierda que no ha sido eliminado.
        int rightOld = 0; // Variable para el soldado más a la derecha que no ha sido eliminado.
        
        // Procesa cada evento de eliminación.
        for (int i = 0; i < b; i++) {
            int l, r; // Variables para los límites izquierdo y derecho de la eliminación.
            cin >> l >> r; // Lee el segmento a eliminar.

            // Ajusta los valores de l y r según los soldados anteriores eliminados.
            if (leftOld <= l) {
                l = leftOld;
            }
            if (rightOld > r) {
                r = rightOld;
            }

            // Marca los soldados eliminados con -1.
            soldiers[l - 1] = -1;
            soldiers[r - 1] = -1;

            // Imprime el soldado más a la izquierda después de la eliminación.
            if (soldiers[0] == -1) {
                cout << "* "; // Si el primer soldado está eliminado, muestra "*".
            } else {
                cout << to_string(soldiers[l - 2]) << " "; // Si no, muestra el soldado anterior.
            }

            // Imprime el soldado más a la derecha después de la eliminación.
            if (soldiers[s - 1] == -1) {
                cout << "*" << endl; // Si el último soldado está eliminado, muestra "*".
            } else {
                cout << to_string(soldiers[r]) << endl; // Si no, muestra el siguiente soldado.
            }

            // Actualiza las variables para el soldado más a la izquierda y derecha después de la eliminación.
            leftOld = l;
            rightOld = r;
        }

        cout << "-" << endl; // Marca el final del conjunto de eliminaciones.
    }
    
    return 0; 
}
