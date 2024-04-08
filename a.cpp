#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        int di = a/k, mo = a%k;
        if(mo == 0){
            cout << di << ' ';
        }
    }
    cout << endl;

    return 0;
}