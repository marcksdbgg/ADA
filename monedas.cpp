// Problema para devolver vuelto con monedas de 0.10 0.20 0.50 1 2 y 5 soles

#include <iostream>
#include <vector>


using namespace std;

// funcion para devolver vuelto
vector<int> devolverVuelto(int vuelto, vector<int> monedas) {
    vector<int> vueltoDevuelto;
    int i = 0;
    while (vuelto > 0) {
        if (vuelto >= monedas[i]) {
            vueltoDevuelto.push_back(monedas[i]);
            vuelto -= monedas[i];
        } else {
            i++;
        }
    }
    return vueltoDevuelto;
}

int main(){
    vector<int> monedas = {50, 20, 10, 5, 2, 1};
    //set precision of monedas
    cout.precision(2);
    int vuelto = 79;
    cout << "Ingrese el vuelto: ";
    vector<int> vueltoDevuelto = devolverVuelto(vuelto, monedas);
    //convertir a double
    cout << "El vuelto es: " << fixed << (double)vuelto/10 << endl;
    cout << "El vuelto es: ";
    for (float i : vueltoDevuelto) {
        cout << i/10 << " ";
    }
    cout << endl;
    return 0;
}

