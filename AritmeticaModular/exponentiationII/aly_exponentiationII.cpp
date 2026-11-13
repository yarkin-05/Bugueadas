// coeficiente binomial
// cses - 1079

#include <bits/stdc++.h>
#include <string>
#include <map>
#include <bit>

using namespace std; 

#define MOD 1000000007

long long exponenciacion(long long a, long long b, int num){
    // long long res = 0;
    long long R = 1;

    if(b==0) {
        return R;
    } else {
        while(b>0){
            if(b&1){ // si el ultimo bit es 1:
                //R*=a;
                R = (R*a) % (MOD-num);
            }
            a = (a*a) % (MOD-num);
            b = b >> 1;
        }
    }
    return (R % (MOD-num));
}

int main() 
{
    int cases = 0;
    cin >> cases;

    for(int i=0; i<cases; i++){
        long long a = 0, b = 0, c = 0;
        cin >> a >> b >> c;

        long long exp_c = exponenciacion(b, c, 1);
        long long exp_b = exponenciacion(a, exp_c, 0);

        cout << exp_b << endl;
    }
}

