#include <iostream>
using namespace std;

int main(){
  int testcases = 0;
  cin >> testcases;


  for(int i = 0; i<testcases ; ++i){

    int num = 0, aux = 0;
    cin >> num;
    
    for(int j = 0; j<num ; j++) cin>>aux;

    // combinacion
    int res = (10-num)*(10-num-1)/2;

    cout<<res*6<<endl;




  }
  


}

