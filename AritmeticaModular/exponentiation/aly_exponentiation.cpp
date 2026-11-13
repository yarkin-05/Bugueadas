// Exponenciación binaria
// cses - 1095

#include <bits/stdc++.h>
#include <string>
#include <map>
#include <bit>

using namespace std; 

#define MOD 1000000007

int main() 
{
    int cases = 0;
    cin >> cases;

    for(int i=0; i<cases; i++){
        long long res = 0;
        long long a = 0;
        long long b = 0; // a = base, b = exponente
        cin >> a >> b;

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
        cout << res << endl;
    }
    
}

