// distributing apples
// cses - 1716

#include <bits/stdc++.h>

using namespace std; 
#define MOD 1000000007
#define LIMIT 10000000

long long exponenciacion(long long a, long long b){
    long long res = 0;
    long long R = 1;

    if(b==0) {
        res = 1;
    } else {
        while(b>0){
            if(b&1){ // si el ultimo bit es 1:
                //R*=a;
                R = (R*a) % MOD;
            }
            a = (a*a) % MOD;
            b = b >> 1;
        }
    }
    res = R % MOD;
    return res;
}

int main() 
{
    vector<long long> factoriales(LIMIT);
    factoriales[0] = 1;
    for(int j=1; j<LIMIT+1; j++){
        factoriales[j] = (factoriales[j-1] * j) % MOD;
    }

    int n = 0; // niños
    int m = 0; // manzanas
    cin >> n >> m;

    //n--; // n - 1

    /* 
        (n+k-1) / n! * (k-1)!
    */

    long long fact_a = factoriales[m+n-1];
    long long fact_b = (factoriales[m] * factoriales[n-1]) % MOD;

    long long exp = (exponenciacion(fact_b, (MOD-2))) % MOD;

    long long res = (fact_a * exp) % MOD;

    cout << res << endl;
    
}

