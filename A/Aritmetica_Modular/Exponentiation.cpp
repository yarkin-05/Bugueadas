/*
  Binomial Coefficients
  https://cses.fi/problemset/task/1079/

  Subtema: Exponenciacion binaria y teorema de Fermat
*/
#define MOD 1000000007
#define LIMIT 10000000
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector < unsigned long long> factorial(LIMIT);

unsigned long long binary_exp(unsigned long long &A)
{

  /*
    a/b % MOD = a b^(m-2) % MOD
    b = b!(a-b)!
  */

  long long respuesta = 1, base = A;
  unsigned long long B = 1000000007 - 2;

  while (B > 0)
  {
    if (B & 1)
      respuesta = (respuesta * base) % MOD;

    //cout<<"respuesta: "<<respuesta<<" base: "<<base<<" bits: "<<B<<" exponente: "<<(B & 1)<<endl;

    base = (base * base) % MOD;
    B = B >> 1;
  }

  return respuesta % MOD;
}


int main()
{
  factorial[0]=1;

  
  for(long long it = 1; it<LIMIT ; ++it) 
  {
    factorial[it] = ((factorial[it-1]%MOD)*(it%MOD)) % MOD;
  }
   

  int testcases = 0;
  cin >> testcases;

  for (int casee = 0; casee < testcases; ++casee)
  {

    long long A = 0, B = 0;
    cin>>A>>B;

    unsigned long long base = (factorial[B]*factorial[A-B])%MOD;
    //cout<<"base: "<<base<<endl;

   // cout<<"A: "<<A<<" , B: "<<B<<endl;


    unsigned long long respuesta = (binary_exp(base)*factorial[A])%MOD;
    cout<<respuesta<<endl;
  }

  return 0;
}


