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
    int t;
    cin >> t;
    while(t--){
        unsigned int a, b, c;
        cin >> a >> b >> c;
       
        unsigned long long k = exp_bin(b,c, MOD - 1);
        unsigned long long res = exp_bin(a, k, MOD);
        cout << res << endl;
    }

    return 0;
}