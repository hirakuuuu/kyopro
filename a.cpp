#include <bits/stdc++.h>
using namespace std;

int main(){
    int tmp = 10;
    long double total = 0.0;
    while(tmp--){
        string _; cin >> _;
        long double t; cin >> t;
        cin >> _;
        total += t;
    }
    total /= 10.0;
    cout << setprecision(13) << total << endl;
    return 0;
}