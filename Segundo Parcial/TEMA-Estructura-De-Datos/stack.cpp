#include<bits/stdc++.h>

using namespace std;

int main() {
    stack<int> pilita; 
    // Crea una pila de enteros llamada `pilita`.

    cout << pilita.empty() << endl;
    // Imprime si la pila está vacía. Como recién se creó, el resultado es `true` (1).

    pilita.push(10);
    // Inserta el número 10 en la parte superior de la pila.

    cout << pilita.empty() << endl;
    // Imprime si la pila está vacía. Ahora debería ser `false` (0), porque hay un elemento en la pila.

    cout << pilita.top() << endl;
    // Muestra el elemento en la parte superior de la pila, que debería ser 10.

    cout << pilita.empty() << endl;
    // Imprime si la pila está vacía, que sigue siendo `false` (0).

    pilita.pop(); 
    // Elimina el elemento de la parte superior de la pila.

    cout << pilita.empty() << endl;
    // Imprime si la pila está vacía. Ahora debería ser `true` (1), porque se eliminó el único elemento.
}
