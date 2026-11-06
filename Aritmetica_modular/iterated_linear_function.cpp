#include <iostream>
using namespace std;
#include <bits/stdc++.h>
 
#define MOD 1000000007

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
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    unsigned int a, b, x;
    unsigned long long n;

    cin >> a >> b;
    cin >> n;
    cin >> x;

    

    if(a == 1){
        a %= MOD;
        x %= MOD;
        b %= MOD;
        n %= MOD;

        unsigned long long res = n * b % MOD;
        res = (res + x) % MOD;
        cout << res << endl;
        return 0;
    }
    if(n == 1){
        unsigned long long res = (exp_bin(a, n, MOD) * x) % MOD;
        res = (res + b) % MOD;
        cout << res << endl;
        return 0;
    }
    unsigned long long first = (exp_bin(a, n, MOD) * x) % MOD;
    
    unsigned long long numerador = exp_bin(a, n, MOD) - 1;
    unsigned long long div = a - 1;

    unsigned long long inverso = exp_bin(div, MOD - 2, MOD);

    unsigned long long second = (numerador * inverso) % MOD;
    second = (second * b) % MOD;

    unsigned long long res = (first + second) % MOD;
    cout << res << endl;
    /*
    unsigned long long second = b;
    for(int i = 1; i < n; i++){
        second += (exp_bin(a, i, MOD) * b) % MOD;
    }
    
    unsigned long long res = (first + second) % MOD;

    cout << res << endl;
    
    */
    return 0;
}