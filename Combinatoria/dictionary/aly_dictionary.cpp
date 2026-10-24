#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std; 

int main() 
{
    int cases;
    cin >> cases;

    for(int i=0; i<cases; i++){
        int posicion1 = 0;
        int posicion2 = 0;
        int vuelta = 0;
        int res = 0;
        char cadena[2];
        cin >> cadena[0] >> cadena[1]; // yz -> 121 122
                                       // za -> 122 97
        
        posicion1 = cadena[0] - 97; // y -> 24     z -> 25
        posicion2 = cadena[1] - 97; // z -> 25     a -> 0

        vuelta = (posicion1 * 25); // 600          625

        if(cadena[0] == 97) res = posicion2; 

        if(posicion1 < posicion2) res = vuelta+posicion2;
        else res = vuelta+(posicion2+1);

        cout << res << endl;

        //if(cadena[0] < cadena[1]) posicion2--;
        

        // cout << vuelta + posicion2 << endl; // 600 + 25  ,    625 + 0
    }
    
}

