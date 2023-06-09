#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n; // Se lee la capacidad del buque (k) y el número de contenedores (n)

    vector<int> p(n+1); // Se crea un vector para almacenar los pesos de los contenedores
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // Se lee el peso de cada contenedor y se almacena en el vector
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0)); // Se crea una matriz para almacenar la cantidad máxima de contenedores que se pueden cargar en el buque con una capacidad determinada
    for (int i = 1; i <= n; i++) { // Se recorre cada contenedor
        for (int j = 1; j <= k; j++) { // Se recorre cada capacidad del buque
            if (p[i] > j) { // Si el peso del contenedor es mayor que la capacidad actual, no se carga el contenedor
                dp[i][j] = dp[i-1][j]; // Se copia el valor de la celda anterior
            } else { // Si el peso del contenedor es menor o igual que la capacidad actual, se compara el valor de la celda anterior con el valor de la celda anterior en la fila i-1 y columna j-peso[i]. Se selecciona el máximo entre ambos valores (cargar o no cargar el contenedor i).
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i]] + 1);
            }
        }
    }

    cout << dp[n][k] << endl; // Se imprime la cantidad máxima de contenedores que se pueden cargar en el buque con la capacidad k

    return 0;
}