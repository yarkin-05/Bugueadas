#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std; 

#define N 1000

int main() 
{
    int cases = 0;
    cin >> cases;

    int res = 0;

    map<int, int> diagonalArriba;
    map<int, int> diagonalAbajo;

    for(int i=0; i<cases; i++){
        int x = 0, y = 0;
        cin >> x >> y;
        
        diagonalAbajo[x-y]++;
        diagonalArriba[x+y]++;
        
    }
    for(const auto& par: diagonalArriba){
        res += par.second * (par.second - 1) / 2;
    }

    for(const auto& par: diagonalAbajo){
        res += par.second * (par.second - 1) / 2;
    }

    cout << res << endl;
}

