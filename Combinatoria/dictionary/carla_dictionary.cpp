#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int a, b;
        string x;
        cin >> x;
        a = x[0] - 'a';
        b = x[1] - 'a';

        //total letras = 26
        //cada letra se combina con 25 letras
        int res = a * 25 + b;
        if(b < a) res ++;
        cout << res << endl;
    }
    
    return 0;
}