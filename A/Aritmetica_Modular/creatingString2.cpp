/*
  Creating Strings 2
  https://cses.fi/problemset/task/1715/
*/
#define MOD 1000000007
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

unsigned long long binary_exp(unsigned long long &A, unsigned long long &B)
{

  /*
    a/b % MOD = a b^(m-2) % MOD
  */

  //cout<<"empeizo binary_exp"<<endl;
  //cout<<"A: "<<A<<" B: "<<B<<endl;

  long long respuesta = 1, base = B;
  unsigned long long exponente = MOD - 2;

  while (exponente > 0)
  {
    if (exponente & 1)
      respuesta = (respuesta * base) % MOD;

    //cout<<"respuesta: "<<respuesta<<" base: "<<base<<" bits: "<<B<<" exponente: "<<(B & 1)<<endl;

    base = (base * base) % MOD;
    exponente = exponente >> 1;
  }
  
  return ((A % MOD) * (respuesta % MOD)) % MOD;
}

// factorial
unsigned long long factorial(unsigned long long &number){

  unsigned long long respuesta = 1;
  for(unsigned long long it = number; it > 1 ; --it){
    respuesta = ( (respuesta % MOD) * (it % MOD) ) % MOD;
  }

  return respuesta;
  
}

int main(){

  string cadena;
  cin>>cadena;

  // factorial n!
  unsigned long long aux = (unsigned long long)(cadena.length() % MOD);
  unsigned long long size = factorial(aux);

  // repeticiones en la cadena
  map <char,unsigned long long> mapa;
  for(unsigned long long character = 0; character < aux ; ++character){
    mapa[cadena[character]]++;
    //cout<<"character: "<<cadena[character]<<" cantidad: "<<mapa[cadena[character]]<<endl;
  }
  
  
  // arreglo de repeticiones
  unsigned long long factoriales[mapa.size()]; // max: 26
  int i = 0; // contador

  for(auto it : mapa){
    factoriales[i] = factorial(it.second);
    ++i;
  }

  // cout arreglo repeticiones
  /*
  for(int it = 0; it < i ; ++it){
    cout<<"factorial: "<<factoriales[it]<<endl;
  }
  */
 
  // 
  unsigned long long dividen = 1;
  for(auto it: factoriales)
    dividen = ( (dividen % MOD) * (it % MOD) ) % MOD;

  cout<<binary_exp(size, dividen)<<endl;

}