#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;

int main(){
  int N = 0, M = 0; // 0 <= 50
  cin>>N>>M;

  bool board[N][M];
  bool aux = true;

  vector<pair<int,int>> filas(N); // primero negras, segundo blancas
  vector<pair<int,int>> columnas(M);

  // O(50^2)
  for(int i = 0; i<N ; i++){
    for(int j = 0; j<M ; j++){
      cin>>aux;
      // 0 = blanca
      // 1 = negra
      if(aux) {
        ++filas[i].first;
        ++columnas[j].first;
      }
      else {
        ++filas[i].second;
        ++columnas[j].second;
      }
    }

  }

  long long result = 0;
  for(auto &it: filas){

    // 2^n -1 - el numero de negras
    if( it.first > 1) result += (long long)pow(2,it.first) - (it.first+1);
    //cout<<"negras: "<<pow(2,it.first) - (it.first+1)<<endl;
    // numero de blancas
    if( it.second > 1) result += (long long)pow(2,it.second) - (it.second+1);
    //cout<<"blancas: "<<pow(2,it.second) - (it.second+1)<<endl;
  }
  
  for(auto &it: columnas){

    // 2^n -1 - el numero de negras
    if( it.first > 1) result += (long long)pow(2,it.first) - (it.first +1);
    // numero de blancas
    if( it.second > 1) result += (long long)pow(2,it.second) - (it.second +1);
  }

  cout<<result+N*M<<endl;

}