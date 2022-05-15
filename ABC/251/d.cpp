#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc251/tasks/abc251_d

int main(){
    int w; cin >> w;
    vector<int> ans;
    int o = 1;
    rep(i, 0, 3){
        rep(j, 1, 101) ans.push_back(j*o);
        o *= 100;
    }
    cout << 300 << endl;
    rep(i, 0, 300){
        if(i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    
    return 0;
}