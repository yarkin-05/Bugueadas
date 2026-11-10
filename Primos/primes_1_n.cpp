#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
#define MAX 1000

unsigned int not_primes[MAX + 1];

int isprime(int n){
    if(n % 2 == 0) return 0;
    for(int i = 3; i <= sqrt(n); i+=2){
        if(n % i == 0) return false;
    }
    return true;
}

void print_primes(int n){
    if(n > 1) cout << 2 << " ";
    for(int i = 3; i <= n; i += 2){
        if(not_primes[i] == true) continue; //no es primo

        //sí es primo
        cout << i << " ";
        int cuadrado = i * i;
        for(int j = cuadrado; j <= n; j += i){
            not_primes[j] = true; //no es primo
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; 
    cin >> n; 

    print_primes(n);

    return 0;
}