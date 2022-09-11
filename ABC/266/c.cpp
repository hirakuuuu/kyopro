#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc266/tasks/abc266_c

int main(){
    vector<int> x(4), y(4);
    rep(i, 0, 4) cin >> x[i] >> y[i];

    rep(i, 1, 5){
        int u1 = x[(i+1)%4]-x[i-1];
        int u2 = y[(i+1)%4]-y[i-1];
        int v1 = x[i%4]-x[i-1];
        int v2 = y[i%4]-y[i-1];

        int gaiseki = u1*v2-u2*v1;
        cout << gaiseki << endl;

        if(gaiseki >  0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}