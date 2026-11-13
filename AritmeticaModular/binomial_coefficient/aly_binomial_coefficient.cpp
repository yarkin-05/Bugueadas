// coeficiente binomial
// cses - 1079

#include <bits/stdc++.h>
#include <string>
#include <map>
#include <bit>

using namespace std; 

#define MOD 1000000007
#define LIMIT 1000000

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

/*long long factorial(int a){
    long long res = 1;
    for(int i=1; i<a+1; i++){
        res = (res*i)%MOD;
    }
    return res;
}¨*/

int main() 
{
    vector<long long> factoriales(LIMIT);
    // Precalculamos los factoriales
    factoriales[0] = 1;
    for(int j=1; j<LIMIT+1; j++){
        factoriales[j] = (factoriales[j-1] * j) % MOD;
    }

    int cases = 0;
    cin >> cases;


    for(int i=0; i<cases; i++){
        int a = 0, b = 0;
        cin >> a >> b;

        long long fact_a = factoriales[a];
        long long fact_b = (factoriales[b] * factoriales[a-b]) % MOD;
        
        long long exp = (exponenciacion(fact_b, (MOD-2)))%MOD;

        long long final = ((fact_a)*(exp)) % MOD;

        cout << final << endl;
    }
    
}

