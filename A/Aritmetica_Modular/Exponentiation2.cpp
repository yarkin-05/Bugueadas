/*
  Expontiation 2
  https://cses.fi/problemset/task/1712/

  Subtema: Exponenciacion binaria y teorema de Fermat
*/
#define MOD 1000000007
#define FI MOD-1
#include <iostream>
#include <math.h>
using namespace std;

unsigned long long binary_exp(unsigned long long &B, unsigned long long &C, unsigned long long mod)
{

  /*
    b^c mod(m)
  */

  unsigned long long respuesta = 1, base = B, exponente = C;

  while (exponente > 0)
  {
    if (exponente & 1)
      respuesta = (respuesta * base) % mod;

    //cout<<"respuesta: "<<respuesta<<" base: "<<base<<" bits: "<<exponente<<" exponente: "<<(exponente & 1)<<endl;

    base = (base * base) % mod;
    exponente = exponente >> 1;
  }

  return respuesta % mod;
}


int main(){

  int testcases = 0;
  cin>>testcases;


  for(int casee = 0; casee < testcases ; ++casee){

    unsigned long long A = 0,  B = 0, C = 0;
    cin>>A>>B>>C;

    //cout<<"hola"<<endl;

    unsigned long long respuesta = 0, exponente = 0;

    // E = b^c mod(FI)
    exponente = binary_exp(B,C, FI);



    respuesta = binary_exp(A,exponente,MOD);
    cout<<respuesta<<endl;
  }

  return 0;

}
