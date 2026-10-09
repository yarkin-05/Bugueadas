#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<int> filas(n);
    vector<int> columnas(m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;

            if(x) {
                filas[i]++;
                columnas[j]++;
            }
        }
    }

    long long conteo = 0;

    for(int& x : filas){
        conteo+= (1LL << x) - 1;

        int ceros = m - x;        
        conteo+= (1LL << ceros) - 1;
    }

    for(int& x : columnas){
        conteo+= (1LL << x) - 1 - x;

        int ceros = n - x;
        conteo+= (1LL << ceros) - 1 - ceros; 

    }

    cout << conteo << endl;
    return 0;
}