/*
  Binomial Coefficients
  https://cses.fi/problemset/task/1079/

  Subtema: Exponenciacion binaria y teorema de Fermat
*/
#define MOD 1000000007
#include <iostream>
using namespace std;

int main(){

  int testcases = 0;
  cin>>testcases;

  for(int casee = 0; casee < testcases ; ++casee){

      int A = 0, B = 0;
      cin>>A>>B;

    if(A == 0 && B == 0) cout<<1<<endl;
    else{

    long long respuesta = 1, base = A;
      while( B > 0){
        if(B & 1)
          respuesta = (respuesta * base) % MOD;

          
       // cout<<"respuesta: "<<respuesta<<" base: "<<base<<" bits: "<<B<<" exponente: "<<(B & 1)<<endl;
        base = (base * base) % MOD;
        B = B >> 1;
      }
      cout<<respuesta%MOD<<endl;
    }
  }

  return 0;

}
