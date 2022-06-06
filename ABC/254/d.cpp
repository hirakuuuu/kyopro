#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc254/tasks/abc254_d

vector<int> e(200005);
void init_p(){
    rep(i, 2, 200005){
        if(e[i]) continue;
        for(int j = i; j < 200005; j += i){
            if(e[j] == 0) e[j] = i;
        }
    }
}



int main(){
    ll n; cin >> n;
    ll ans = 0;

    vector<bool> sq(n+1, false);
    for(int i = 1; i*i <= n; i++){
        sq[i*i] = true;
    }
    vector<vector<int>> d(n+1);
    rep(i, 1, n+1){
        for(int j = i; j <= n; j += i) d[j].push_back(i);
    }

    vector<int> cnt(n+1);

    rep(i, 1, n+1){
        int f = 0;
        rep(j, 0, d[i].size()) if(sq[d[i][j]]) f = d[i][j];
        cnt[i/f]++;
    }

    rep(i, 1, n+1){
        ans += cnt[i]*cnt[i];
    }

    cout << ans << endl;
    
    return 0;
}