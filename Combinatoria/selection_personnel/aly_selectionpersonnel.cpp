
#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std; 

/*long long combinatoria(int n, int m){ // n = 7, m = 5
    double resta = n-m; // resta = 2
    long double operacion = n; // 7 
    double max = m; // 5


    

    if(resta == 1) {
        return n;
    }
    if((n-m)==0 || m == 0){
        return 1;
    }

    vector<bool> booleanos;
    
    for(int j=n-1; j>max; j--){ // j = 6; j > 5 ; j--;
        operacion = operacion*j / resta; // 7 = 7*(6k) / 2
        //operacion = (j*(j-1)) / m ; // 1*10/3 = 3
        resta--; // j = 6
        //cout << "Esta es la operacion al momento j= " <<j << " " << operacion << endl;
    }

    return operacion;

}*/

int main() 
{
    cin.tie(0)->sync_with_stdio(0);

    int n = 0;
    cin >> n;
    int m = 7;
    unsigned long long res = 0;

    for(int i=0; i<3; i++){ // Para 7, 6 y 5
        int resta = n-m;
        
        if(resta == 1) {
        res += n;
        m-=1;
        continue;
        }
        if(resta==0 || m == 0){
            res += 1;
            m-=1;
            continue;
        } 

        vector<int> vec = {7, 6, 5, 4, 3, 2};
        int j = 0;
        int div = 0;
        while(!vec.empty() && j < vec.size()){
            int mult = n*(n-1);
            if(mult/vec[j] %vec[j] == 0){ // si es divisible
                div += mult/vec[j];
                vec.erase(vec.begin() + j); // lo saco del vector
                j = 0;
            } else {
                if(j < vec.size()) j++;
            }
            n -= 1;
        }

        res += div;

        cout << " Res: " << res << endl;
        m-=1; // 6 y luego 5
        n = val-1;
    }

    /*cout << "Con 5: " << combinatoria(n,5) << endl;
    cout << "Con 6; " << combinatoria(n,6) << endl;
    cout << "Con 7: " << combinatoria(n,7) << endl;
    
    long double res = combinatoria(n, 5) + combinatoria(n, 6) + combinatoria(n, 7); */

    cout << res << endl;
}

