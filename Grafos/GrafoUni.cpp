#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar una arista
struct Edge {
    int to; // Nodo destino
    int weight; // Peso de la arista
    Edge(int t, int w) : to(t), weight(w) {} // Constructor
};

// Estructura para representar un grafo
class Graph {
public:
    int V; // Número de nodos
    vector<vector<Edge>> adj; // Lista de adyacencia

    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Función para agregar una arista al grafo
    void addEdge(int u, int v, int w) {
        adj[u].push_back(Edge(v, w));
    }
};

int main() {
    int V, E;
    cout << "Ingrese el número de nodos y el número de aristas: ";
    cin >> V >> E;

    Graph g(V); // Se crea un grafo con V nodos

    cout << "Ingrese las aristas (nodo origen, nodo destino, peso):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w); // Se agrega la arista al grafo
    }

    // Se imprime la lista de adyacencia del grafo
    for (int u = 0; u < V; u++) {
        cout << "Nodo " << u << ": ";
        for (auto e : g.adj[u]) {
            cout << "(" << e.to << ", " << e.weight << ") ";
        }
        cout << endl;
    }

    return 0;
}