#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
#define MAX 100000000

int not_primes[MAX + 1];
unsigned int contador = 0;

int isprime(int n){
    if(n % 2 == 0) return 0;
    for(int i = 3; i <= sqrt(n); i+=2){
        if(n % i == 0) return false;
    }
    return true;
}

void print_primes(int n){
    if(n > 1) contador++; //por el 2
    for(int i = 3; i <= n; i += 2){
        if(not_primes[i]) continue; //no es primo

        //sí es primo
        contador++;
        unsigned long long j = (unsigned long long) i * i;
        for(; j <= n; j += i){
            not_primes[j] = true; //no es primo
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; 
    cin >> n; 

    print_primes(n);

    cout << contador << endl;

    return 0;
}