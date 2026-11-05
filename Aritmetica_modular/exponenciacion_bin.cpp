#include <iostream>
using namespace std;
#include <bits/stdc++.h>
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        unsigned int a, b;
        cin >> a >> b;
       
        unsigned long long res = 1; 
        unsigned long long base = a;
 
        while (b > 0){
            //con & 1 si impar, 0 si par
            if(b & 1){
                res *= base;
                res %= 1000000007;
            }
            base *= base;
            base %= 1000000007;            
            b >>= 1; //desplazamos 1 a la derecha: dividimos entre 2 
        }
 
        cout << res << endl;
    }
 
    return 0;
}