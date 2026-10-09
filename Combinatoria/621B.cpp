#include <iostream>
#include <unordered_map>
using namespace std;

int func(int &size)
{
  return (size * (size - 1)) / 2;
}

int main()
{

  int bishops = 0;
  cin >> bishops;

  unordered_map<int, int> arrBishopsUp;
  unordered_map<int, int> arrBishopsDown;
  // suma -> vector de coordenadas
  

  for (int i = 0; i < bishops; ++i)
  {
    int x, y;
    cin >> x >> y;
    // diagonal hacia arriba
    arrBishopsUp[x+y]++;  
    arrBishopsDown[x-y]++;

 
  }

  int result = 0;
  // imprimir mapas


  // diagonal hacia arriba
  for (auto &it : arrBishopsUp)
  {
    int qty = it.second;
    if( qty < 2) continue;
    result += func(qty);
  }

  // diagonal hacia abajo
  for (auto &it : arrBishopsDown)
  {
    int qty = it.second;
    if( qty < 2) continue;
    result += func(qty);
  }

  cout << result << endl;
}


/*
    for (auto &it : arrBishopsUp)
  {
    cout << "Diagonal hacia arriba: " << it.first << " cantidad: " << it.second << endl;
  }

  for (auto &it : arrBishopsDown)
  {
    cout << "Diagonal hacia abajo: " << it.first << " cantidad: " << it.second << endl;
  }


*/