// linear function
// codeforces - D678

#include <bits/stdc++.h>

using namespace std; 

#define MOD 1000000007

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
    long long A = 0; 
    long long B = 0; 
    long long n = 0; 
    long long x = 0;

    cin >> A >> B >> n >> x;

    long long parte_A = ((exponenciacion(A, n))*(x%MOD))%MOD;
    //cout << "Parte_A: " << parte_A << endl;
    long long parte_B = 0;

    for(long long i=0; i<n; i++){
        parte_B = ((parte_B) + exponenciacion(A, i))%MOD;
    }

    parte_B = ((parte_B)*(B%MOD))%MOD;

    long long res = ((parte_A%MOD) + (parte_B%MOD))%MOD;

    cout << res << endl;
}

