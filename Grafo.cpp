#include <iostream>
#include <vector>

using namespace std;

struct Nodo {
    int id;
    // otros atributos del nodo
};

struct Arista {
    int origen;
    int destino;
    // otros atributos de la arista
};

class Grafo {
private:
    int V; // número de vértices
    vector<Nodo> nodos; // vector de nodos
    vector<Arista> aristas; // vector de aristas

public:
    Grafo(int V) {
        this->V = V;
        nodos.resize(V);
    }

    void agregarNodo(int id) {
        nodos[id].id = id;
        // inicializar otros atributos del nodo
    }

    void agregarArista(int origen, int destino) {
        Arista arista = {origen, destino};
        aristas.push_back(arista);
    }

    void imprimirGrafo() {
        for (int i = 0; i < V; ++i) {
            cout << "Nodo " << nodos[i].id << endl;
            // imprimir otros atributos del nodo
            cout << "Aristas: ";
            for (auto arista : aristas) {
                if (arista.origen == i) {
                    cout << "(" << nodos[arista.origen].id << ", " << nodos[arista.destino].id << ") ";
                } else if (arista.destino == i) {
                    cout << "(" << nodos[arista.destino].id << ", " << nodos[arista.origen].id << ") ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Grafo g(5);
    g.agregarNodo(0);
    g.agregarNodo(1);
    g.agregarNodo(2);
    g.agregarNodo(3);
    g.agregarNodo(4);
    g.agregarArista(0, 1);
    g.agregarArista(0, 4);
    g.agregarArista(1, 2);
    g.agregarArista(1, 3);
    g.agregarArista(1, 4);
    g.agregarArista(2, 3);
    g.agregarArista(3, 4);
    g.imprimirGrafo();
    return 0;
}