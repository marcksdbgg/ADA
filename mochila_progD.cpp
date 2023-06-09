//Problema de la mochila con programacion dinamica y mostrar la tabla

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n), v(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i] >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            if (p[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i - 1]] + v[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
    cout << dp[n][m] << endl;
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}