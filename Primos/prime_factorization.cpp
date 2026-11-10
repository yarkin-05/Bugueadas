#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void primes(unsigned long long n){
    unsigned long long tmp = n;
    unsigned long long primo = 2;

    while(primo * primo <= tmp){
        while(tmp % primo == 0) {
            cout << primo << " ";
            tmp /= primo;
        }

        if(primo == 2) primo++;
        else primo+=2;
        
    }
    
    //lo que quedó es otro primo
    if(tmp > 1) cout << tmp << endl;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    unsigned long long n; 
    cin >> n; 

    primes(n);
    return 0;
}