#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX 10000000
unsigned int prime_factors[MAX + 1];

//en lugar de ver si es o no primo, anotamos el factor primo de cada num
//para memorización
void fill_array(){
    for(unsigned int i = 2; i <= MAX; i++){
        if(prime_factors[i]) continue; //ya está llena

        //sí es primo
        for(unsigned int j = i; j <= MAX; j += i){
            if(!prime_factors[j]) prime_factors[j] = i; 
            //j no es primo; ponemos su menor factor primo i
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; 
    cin >> t;
    fill_array();
    
    while(t--){
        unsigned long long n; 
        cin >> n; 

        while(n>1){
            cout << prime_factors[n] << " ";
            n /= prime_factors[n];
        }

        if(n > 1) cout << n;
        cout << endl;
    }
    return 0;
}