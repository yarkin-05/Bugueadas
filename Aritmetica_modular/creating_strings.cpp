#include <iostream>
using namespace std;
#include <bits/stdc++.h>
 
#define MOD 1000000007
#define MAX 1000000

unsigned long long factorial[MAX + 1];

unsigned long long exp_bin(unsigned long long base, unsigned long long exp, unsigned long long mod){
    unsigned long long res = 1;

    while(exp > 0){
        if(exp & 1){
            res = (res * base) % mod;
        }

        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void precalcular(unsigned long long *factorial){
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    precalcular(factorial);

    string s;
    cin >> s;
        
    unsigned int n = s.length();
            
    int i = 0;
    map<char, int> frecuencias;
        
    while(i < n){
        frecuencias[s[i]]++;
        i++;
    }

    unsigned long long div = 1;
    for (auto& [clave, valor] : frecuencias){
        div = (div * factorial[valor]) % MOD;
        //cout << clave << valor << endl;
    }

    //inverso modular
    unsigned long long inv = exp_bin(div, MOD - 2, MOD);

    unsigned long long res = (factorial[n] * inv) % MOD;

    cout << res << endl;
}