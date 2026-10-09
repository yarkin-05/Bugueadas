#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int not_used;
        cin >> not_used;

        int x;
        vector<int> v(not_used);
        for (int i = 0; i < not_used; i++){
            cin >> v[i];
        }
        
        int posibles = 10 - not_used;
        int comb = posibles*(posibles - 1)/2;
        cout << comb * 6 << endl;
    }
    
    return 0;
}