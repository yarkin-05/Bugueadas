    #include <bits/stdc++.h>
    #include <string>
    #include <map>

    using namespace std; 

    int main() 
    {
        int x, y;
        cin >> x >> y;
        
        long long total = x*y; // matriz total
        long long res = 0;
        long long setsy = 0, setsx = 0;

        map<int, long long> contadorX; // contamos la cantidad de 0 o 1 en cada fila
        map<int, long long> contadorY; // en cada columna

        vector<vector<int>> matriz(x, vector<int>(y));

        for(int i=0; i<x; i++){ 
            long long contadorBlanco = 0;
            long long contadorNegro = 0;

            for(int j=0; j<y; j++){
                cin >> matriz[i][j];
                //cout << matriz[i][j]; 
                if(matriz[i][j]==1) {
                    contadorNegro++; // si es 1, le sumamos a 1
                }  
                else contadorBlanco++; // si no le sumamos a 0

                //cout << "ContadorX para negros: " << contadorX[1] << endl;
                //cout << "ContadorX para blancos: " << contadorX[0] << endl;

            }

            contadorX[1] += pow(2, contadorNegro) - 1 - contadorNegro;
            contadorX[0] += pow(2, contadorBlanco) - 1 - contadorBlanco;

            //cout << "Subconjuntos de blancos en la fila" << i << ": " << contadorX[0] << endl;
            //cout << "Subconjuntos de negros en la fila" << i << ": " << contadorX[1] << endl; 
            //cout << "contador de 0: " << contadorX[0];
            
        }
        setsx = contadorX[0] + contadorX[1];
        //cout << "Total de sets horizontales: " << setsx << endl;

        for(int i=0; i<y; i++){ 
            long contadorBlanco = 0;
            long contadorNegro = 0;
            for(int j=0; j<x; j++){

                if(matriz[j][i]==1) {
                    contadorNegro++; // si es 1, le sumamos a 1
                }  
                else contadorBlanco++; // si no le sumamos a 0
            }
            contadorY[1] += pow(2, contadorNegro) - 1 - contadorNegro;
            contadorY[0] += pow(2, contadorBlanco) - 1 - contadorBlanco;
            
        }
        setsy = contadorY[0] + contadorY[1];
        //cout << "Total de sets verticales: " << setsx << endl;

        res = setsy + setsx + total;

        cout << res << endl;
        
        
    }

