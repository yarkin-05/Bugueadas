    #include <bits/stdc++.h>
    #include <string>
    #include <map>

    using namespace std; 

    long long potencia(long long a){
        long long ini = 2;
        for(int i=0; i<a-1; i++){
            ini = (ini * 2) % 1000000007;
        }
        return ini;
    }

    int main() 
    {
        int flagstones = 0;
        cin >> flagstones;
        
        long long sets = 0;

        map<int, long long> colores; 
        for(int i=0; i<flagstones; i++){
            int color = 0;
            cin >> color;
            colores[color]++;
        }

        for(const auto& color: colores){
            sets += potencia(color.second) - 1;
        }
        
        cout << sets % 1000000007 << endl;
    }

