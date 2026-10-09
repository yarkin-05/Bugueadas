#include <iostream>
using namespace std;

/*
  2 letters
  diff letters
  ab ≠ ba ( orden si importa )

  - letter a is less than letter b
*/


int main(){
  int testcases = 0;
  cin>>testcases; 
  string word = "";

  for(int i = 0; i<testcases ; ++i){
    cin>>word;

    /*
        26!    = 
      (26-2)!


      25*26
       0 ab, ac, ad, ae, af, ag, aj ... 25 combinaciones
       1 ba, bc, bd, be, bf, bg, bj ...
      ca
      da
      ea
      fa
      ga
      ha


    */

    int letra1 = word[0] - 97; // valor de a en ASCII 
    int letra2 = word[1] - 97; 
   
    int res = (letra1)*25;

    // ba bc bd be 
    if( letra1  < letra2) res += letra2;
    else res += letra2+1;
    //                         

    if( word[0] == 'a') cout<<letra2<<endl;
    else cout<<res<<endl;

  }


}