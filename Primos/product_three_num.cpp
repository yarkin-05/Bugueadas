#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; 
    cin >> t;
    //t = 1;

    while (t--) {
        unsigned long long n; 
        cin >> n;
        //n = 64;
        
        vector<unsigned long long> v;

        unsigned long long factor = 2;
        unsigned long long tmp = n;

        while(v.size() < 3 && (tmp > 1) && (factor * factor <= tmp)){
            if(tmp % factor == 0){
                v.push_back(factor);
                tmp /= factor;
            }
            factor++;
        }
        
        //si quedó en tmp, toca cambiar el valor del último añadido
        if(tmp > 1 && v.size() == 3){
            v[2] *= tmp;
            tmp = 1;
        }

        //sí quedó y solo tenemos 2 elementos
        else if(v.size() == 2 && tmp > v.back()) {
            v.push_back(tmp);
            tmp = 1;
        }

        //están todos y no hay residuos
        if(v.size() == 3 && tmp == 1){
            cout << "YES" << endl;

            for(unsigned long long x: v){
                cout << x << " ";
            }

        }
        //no se cumplen las condiciones
        else cout << "NO";
        
        cout << endl;
    } 
    return 0;
}