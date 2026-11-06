#include <iostream>
using namespace std;
#include <bits/stdc++.h>
 
#define MOD 122333221
#define MAX 100000

unsigned long long factorial[MAX + 1];

unsigned long long fact_bin(unsigned long long base, unsigned long long exp, unsigned long long mod){
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
    int t;
    cin >> t;
    precalcular(factorial);

    while(t--){
        unsigned int a, b;
        cin >> a>> b;
            
        unsigned long long fact_a = factorial[a];
        unsigned long long fact_b = factorial[b];
        unsigned long long fact_resta = factorial[a - b];

        unsigned long long bin_b = (fact_b * fact_resta) % MOD;

        unsigned long long inv_b = fact_bin(bin_b, MOD - 2, MOD);
        unsigned long long res = (fact_a * inv_b) % MOD;
        
        cout << res << endl;
    }
 
    return 0;
}