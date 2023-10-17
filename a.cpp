#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    long double sum = 0.0;
    for(int i = 1; i <= n; i++){
        sum += (long double)log10(i);
    }
    int ans = ceil(sum);
    cout << ans << endl;
    
    return 0;
}