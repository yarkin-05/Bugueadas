#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> mapa;

    while (n--){
        int x;
        cin >> x;
        mapa[x];
        mapa[x] ++;
    }
    unsigned long long conteo = 0;

    for (const auto& par : mapa) {
        unsigned long long subconjuntos = 2;
        
        for (int i = 1; i < par.second; i++){
            subconjuntos *= 2;
            subconjuntos %= 1000000007;
        }

        conteo += subconjuntos - 1;
        conteo %= 1000000007;
    }

    cout << conteo << endl;
    return 0;
}