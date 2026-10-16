/*
  Selection or Personnel

  source: https://codeforces.com/problemset/problem/630/F

*/
#include <iostream>
#include <vector>
using namespace std;

// combinacion
unsigned long long f(int &N, int i){

  // saco factorial y el vector de bools
  int i_factorial = 0;
  vector <bool> usados(i);
  usados[0] = false;
  usados[1] = false;
  usados[2] = false;
  usados[3] = false;
  usados[4] = false;

  if( i == 5) 
    i_factorial = 5*4*3*2;
  else if( i == 6) {
    i_factorial = 6*5*4*3*2;
    usados[5] = false; 
  }
  else {
    i_factorial = 7*6*5*4*3*2;
    usados[6] = false;
  }

  // vector de booleanos

  unsigned long long result = 1;
  unsigned long long dividend = 1;


  if(i > (N - i)) {
    // 5 > 8 - 5 = 3
    /*
     8 7 6 5 4 3 2 1
     5 4 3 2 1 (8-5)

      8 7 6 5 4 3 2 1
      6 5 4 3 2 1 (8-6)

      8 7 6 5 4 3 2 1
      7 6 5 4 3 2 1 (8-7)
    */
    int lesser = N-i; // 3 , 2, 1
    unsigned long long dividiend = 1;
    for(int it = N ; it > i ; --it){

      result *= (unsigned long long)it;
      if( lesser > 1) {
        dividend *= (unsigned long long)lesser;
        --lesser;
      }
    }

    result /= dividend;

  }else{
    /*
     624 * 623 * 622 * 621 * 620
     5 4 3 2 1 ( 619)!

     N - i = 619
    */

    for(int it = N ; it > (N - i) ; --it){

     // cout<<result<<" * "<<it<<endl;

      result *= (unsigned long long)it;
      for(int usado = 0; usado < i ; ++usado){

        if( result % (usado+1) == 0 && usados[usado] == false) {
         // cout<<result<<" / "<<(usado+1)<<endl;
          usados[usado] = true;
          result /= (usado+1);
          i_factorial /= (usado+1);
        }

      }
      
    }

    result /= (unsigned long long)i_factorial;
  }

  return result;
}


int main(){
  cin.tie(0)->sync_with_stdio(0);


  int N = 0; // 7 - 777
  cin>>N;

  // para N = 8


  // calcular para 5, 6 y 7

  if( N == 7 ) cout<< 1 + 21 + 7<<endl; // caso para N == 7
  else{

    unsigned long long result = 0;
    for(int i = 5; i<8 ; ++i){

      result += f(N,i);
      
    }

    cout<<result<<endl;
  }

}