/*
  problem: 106718I - Fruit Punch
  https://codeforces.com/gym/106718/problem/I

  Solution: Teorema de Fermat
  https://codeforces.com/topic/157595/en10?mobile=false&locale=en
*/
#define MOD 122333221
#include <iostream>
using namespace std;

long long lol(int &alejandra, int &sister, bool &primerMenor){

    /*
      alejandra!
      sister!(alejandra-sister)!

      10 y 6

      10!
      6!(10-6)!

      10 9 8 7 (6 5 4 3 2 1)
      6 5 4 3 2 1 (4 3 2 1)

      --------------------
      10 y 3
        
        10!
      3!(10-3)!

      10 9 8 7 6 5 4 3 2 1
      3 2 1 (7 6 5 4 3 2 1)
      
      
  */

  long long combinatoria = 1;
  long long divisor = 1;
  if(primerMenor){
    // el primero es menor

    int j = sister;
    for(int i = alejandra; i > (alejandra - sister) % MOD ; --i){
 
      cout<<combinatoria<<" * "<<i<<" / "<<j<<endl;
      combinatoria *= (long long)i % MOD;
      divisor *= (long long)j % MOD;
      --j;
  
    }
  }else{

    int j = alejandra - sister;

    for(int i = alejandra; i > sister ; --i){
 
 
      cout<<combinatoria<<" * "<<i<<" / "<<j<<endl;
      combinatoria *= (long long) i % MOD;
      divisor *= (long long)j % MOD;
      --j;
    }

  }

  return (combinatoria / divisor) % MOD;

}

int main(){

  int testcases = 0;
  cin>>testcases;

  int alejandra = 0, sister = 0;
  bool primerMenor = true;

  for(int i = 0; i<testcases ; i++){
    cin>>alejandra>>sister;

    if( alejandra - sister > sister) cout<<lol(alejandra,sister,primerMenor = true)<<endl;
    else if( alejandra == sister) cout<<0<<endl; // le quitó todo los ingredientes
    else cout<<lol(alejandra,sister,primerMenor = false);
  }


}