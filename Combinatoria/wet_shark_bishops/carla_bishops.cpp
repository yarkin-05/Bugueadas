#include <iostream>
using namespace std;
#include <bits/stdc++.h>
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    map<unsigned short, unsigned short> izq;
    map<unsigned short, unsigned short> der;
 
    int m = 0;
    while (m < n){
        unsigned short x, y;
        cin >> x >> y;
        izq[y-x]++;
        der[y+x]++;
        m++;
    }
    int conteo = 0;
    for(const auto& par : izq){
        conteo += par.second * (par.second - 1) / 2;
    }
    for(const auto& par : der){
        conteo += par.second * (par.second - 1) / 2;
    }
 
    cout << conteo << endl;
    return 0;
}
