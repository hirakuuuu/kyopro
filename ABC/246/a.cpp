#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc246/tasks/abc246_a

int main(){
    vector<int> x(3), y(3);
    rep(i, 0, 3) cin >> x[i] >> y[i];
    int x4 = 0, y4 = 0;
    rep(i, 0, 3){
        if(x[i] == x[(i+1)%3]) x4 = x[(i+2)%3];
        if(y[i] == y[(i+1)%3]) y4 = y[(i+2)%3];

    }
    cout << x4 << " " << y4 << endl;
    return 0;
}