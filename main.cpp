#include <iostream>
#include <iomanip>
using namespace std;

template <int N>
struct sparse_set {
    int n;
    int denso[N], esparcido[N];

    // Constructor: inicializa 'n' a 0, y el array a -1 (vacío)
    sparse_set() {
        n = 0;
        for (int i = 0; i < N; ++i) {
            esparcido[i] = -1;
        }
    }


    bool buscar(int num) const {
        cout << "\n--- Proceso de Busqueda ---" << endl;
        cout << "Buscando el numero " << num << " en el sparse set..." << endl;
        for (int i = 0; i < n; i++) {
            cout << "Comparando " << denso[i] << " en el indice " << i << endl;
            if (denso[i] == num) {
                cout << "¡Encontrado en el indice " << i << " del array denso!" << endl;
                return true;
            }
        }
        cout << "El numero " << num << " no esta presente" << endl;
        return false;
    }

    void insertar(int num) {
        cout << "\n--- Proceso de Insercion ---" << endl;
        if (buscar(num)) {
            cout << "El numero " << num << " ya esta presente. No se puede insertar de nuevo" << endl;
            return;
        }
        denso[n] = num;
        esparcido[num] = n;
        cout << "Insertando " << num << " en el indice " << n << " del array denso" << endl;
        n++;
        visualizar();
    }


    void eliminar(int num) {
        cout << "\n--- Proceso de Eliminacion ---" << endl;
        if (!buscar(num)) {
            cout << "El numero " << num << " no esta presente. No se puede eliminar" << endl;
            return;
        }
        int index = esparcido[num];
        cout << "Eliminando " << num << " del indice " << index << " del array denso" << endl;

        denso[index] = denso[n - 1];
        esparcido[denso[n - 1]] = index;

        n--;
        esparcido[num] = -1;

        cout << "Numero " << num << " eliminado correctamente" << endl;
        visualizar();
    }

    void visualizar() const {
        cout << "\n=== Estructura Sparse Set ===" << endl;

        cout << "Array denso:" << endl;
        cout << "Indice: ";
        for (int i = 0; i < n; i++) {
            cout << setw(5) << i << " "; // Espaciado para índices
        }
        if (n == 0) cout << "(vacio)";
        cout << endl;

        cout << "Valor : ";
        for (int i = 0; i < n; i++) {
            cout << "[";
            cout << setw(3) << denso[i] << "] "; // Cuadro alrededor de cada valor
        }
        cout << endl;

        cout << "Array esparcido:" << endl;
        cout << "Indice: ";
        for (int i = 0; i < N; i++) {
            cout << setw(5) << i << " "; // Espaciado para índices
        }
        cout << endl;

        cout << "Valor : ";
        for (int i = 0; i < N; i++) {
            cout << "[";
            cout << setw(3) << esparcido[i] << "] "; // Cuadro alrededor de cada valor
        }
        cout << endl;
    }
};

int main() {
    sparse_set<10> conjunto;

    cout << "*** Implementacion de un Sparse Set ***" << endl;

    cout << "\n--- Primero, insertamos 2, 4, 6 y 8 ---" << endl;
    conjunto.insertar(2);
    conjunto.insertar(4);
    conjunto.insertar(6);
    conjunto.insertar(8);
    conjunto.insertar(6); //

    cout << "\n--- Segundo, buscamos ---" << endl;
    conjunto.buscar(8);
    conjunto.buscar(7);

    cout << "\n--- Tercero, eliminamos 2 y 7---" << endl;
    conjunto.eliminar(2);
    conjunto.eliminar(7);

    conjunto.buscar(2);
    return 0;
}