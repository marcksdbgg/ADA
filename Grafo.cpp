#include <iostream>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>

using namespace std;

struct Nodo {
    int id;
    // otros atributos del nodo
};

struct Arista {
    int origen;
    int destino;
    int peso;
    // otros atributos de la arista
};

class Grafo {
private:
    int V; // número de vértices
    vector<Nodo> nodos; // vector de nodos
    vector<Arista> aristas; // vector de aristas
    unordered_map<int, vector<int>> listaAdy; // lista de adyacencia

public:
    Grafo(int V) {
        this->V = V;
        nodos.resize(V);
    }

    void agregarNodo(int id) {
        nodos[id].id = id;
        // inicializar otros atributos del nodo
    }

    void agregarArista(int origen, int destino, int peso = 1) {
        Arista arista = {origen, destino, peso};
        aristas.push_back(arista);
        listaAdy[origen].push_back(destino);
        listaAdy[destino].push_back(origen);
    }

    void imprimirGrafo() {
        for (int i = 0; i < V; ++i) {
            cout << "Nodo " << nodos[i].id << endl;
            // imprimir otros atributos del nodo
            cout << "Aristas: ";
            for (auto arista : aristas) {
                if (arista.origen == i) {
                    cout << "(" << nodos[arista.origen].id << ", " << nodos[arista.destino].id << ", " << arista.peso << ") ";
                } else if (arista.destino == i) {
                    cout << "(" << nodos[arista.destino].id << ", " << nodos[arista.origen].id << ", " << arista.peso << ") ";
                }
            }
            cout << endl;
        }
    }

    vector<int> obtenerVecinos(int nodo) {
        return listaAdy[nodo];
    }

    int obtenerPesoArista(int origen, int destino) {
        for (auto arista : aristas) {
            if ((arista.origen == origen && arista.destino == destino) || (arista.origen == destino && arista.destino == origen)) {
                return arista.peso;
            }
        }
        return -1; // arista no encontrada
    }

    void dibujarGrafo() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Grafo");
        window.setFramerateLimit(60);

        // crear círculos para los nodos
        vector<sf::CircleShape> circulos;
        for (int i = 0; i < V; ++i) {
            sf::CircleShape circulo(20);
            circulo.setFillColor(sf::Color::White);
            circulo.setOutlineThickness(2);
            circulo.setOutlineColor(sf::Color::Black);
            circulo.setPosition(50 + i * 100, 50);
            circulos.push_back(circulo);
        }

        // crear líneas para las aristas
        vector<sf::VertexArray> lineas;
        for (auto arista : aristas) {
            sf::VertexArray linea(sf::Lines, 2);
            linea[0].position = sf::Vector2f(50 + arista.origen * 100 + 20, 50 + 20);
            linea[1].position = sf::Vector2f(50 + arista.destino * 100 + 20, 50 + 20);
            linea[0].color = sf::Color::Black;
            linea[1].color = sf::Color::Black;
            lineas.push_back(linea);
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);

            // dibujar círculos y líneas
            for (auto circulo : circulos) {
                window.draw(circulo);
            }
            for (auto linea : lineas) {
                window.draw(linea);
            }

            window.display();
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
    g.agregarArista(0, 1, 2);
    g.agregarArista(0, 4, 1);
    g.agregarArista(1, 2, 3);
    g.agregarArista(1, 3, 1);
    g.agregarArista(1, 4, 2);
    g.agregarArista(2, 3, 1);
    g.agregarArista(3, 4, 1);
    g.dibujarGrafo();
    return 0;
}