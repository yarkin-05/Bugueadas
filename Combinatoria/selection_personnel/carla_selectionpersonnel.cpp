#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; 
    cin >> n;
    //N cantidad disponible, M cantidad en cada grupo
    //N! / (M! (N – M)!)

    //sumar de 5 - 7 personas.
    //verificar que sí se acompleta un grupo 

    unsigned long long sumatoria = 0;

    for(int cant = 5; cant<=7; cant++){
        int resta = n - cant;
        int mayor = max(resta, cant);
        int menor = min(resta,cant);
        int num = mayor + 1;
        unsigned long long res_num = 1;

        if(menor == 0) menor = 1;

        int i = 0;
        while(num <= n){
            res_num *= num;
            if(i < menor){
                res_num /= i+1;
                i++;
            }
            num++;
        }

        sumatoria += res_num;
    }
    cout << sumatoria << '\n';
    return 0;
}