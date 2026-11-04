#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std; 

int main() 
{
    // DOS DIGITOS DIFERENTES
    // CADA DIGITO SE REPITE 2 VECES
    // 4 DIGITOS POR CONTRASEÑA

    int cases, not_used;
    cin >> cases;

    for(int i=0; i<cases; i++){
        cin >> not_used;
        long long pares = 0;
        long long combinaciones = 0;
        for(int j=0; j<not_used; j++){
            int values;
            cin >> values;

            long long nums;
            nums = 10 - not_used; // cuantos nums diferentes

            pares = nums * (nums - 1) / 2;

            combinaciones = pares * 6;
            
        }
        cout << combinaciones << endl;
    }
    
}

