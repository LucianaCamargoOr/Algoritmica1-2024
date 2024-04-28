#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)


int main() {
    int stations, aliceHome; // `stations` es el número total de estaciones y `aliceHome` es la posición de la casa de Alice.
    cin >> stations >> aliceHome; // Lee el número de estaciones y la posición de la casa de Alice.

    vector<int> stations1(stations); // Vector para la primera línea de estaciones.
    vector<int> stations2(stations); // Vector para la segunda línea de estaciones.

    // Lee el estado de las estaciones en la primera línea.
    for (int i = 0; i < stations; i++) {
        cin >> stations1[i]; 
    }

    // Lee el estado de las estaciones en la segunda línea.
    for (int i = 0; i < stations; i++) {
        cin >> stations2[i];
    }

    if (stations1[0] == 0) {
        // Si la primera estación de la línea 1 es inaccesible, Alice no puede empezar su viaje.
        cout << "NO" << endl;
        return 0; // Termina 
    }

    if (stations1[aliceHome - 1] == 1) {
        // Si la casa de Alice en la línea 1 es accesible, Alice puede llegar allí.
        cout << "YES" << endl;
        return 0; 
    }

    if (stations2[aliceHome - 1] == 0 && stations1[aliceHome - 1] == 0) {
        // Si ambas líneas tienen estaciones inaccesibles donde está la casa de Alice, Alice no puede llegar.
        cout << "NO" << endl;
        return 0; 
    }

    // Verifica si Alice puede cambiar de línea para llegar a casa.
    for (int i = aliceHome; i < stations; i++) {
        if (stations1[i] == 1 && stations2[i] == 1) {
            // Si existe una estación después de la casa de Alice donde ambas líneas están accesibles, Alice puede llegar.
            cout << "YES" << endl;
            return 0; 
        }
    }

    // Si ninguna de las condiciones anteriores se cumple, Alice no puede llegar a casa.
    cout << "NO" << endl;

    return 0;
}
