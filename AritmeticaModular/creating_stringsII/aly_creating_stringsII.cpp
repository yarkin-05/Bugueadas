// creating strings
// cses - 1715

#include <bits/stdc++.h>
#include <string>
#include <map>
#include <bit>

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
    int A = 0; 
    int B = 0; 
    long long n = 0; 
    int x = 0;

    cin >> A >> B >> n >> x;

    long long parte_A = ((exponenciacion(A, n))*x)%MOD;
    long long parte_B = 0;

    for(int i=0; i<n; i++){
        parte_B = parte_A + (exponenciacion(A, i));
    }

    parte_B = (parte_B*B)%MOD;

    long long res = parte_A + parte_B;

    cout << res << endl;
}

