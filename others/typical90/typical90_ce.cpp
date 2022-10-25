#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_ce

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> c(n+1);
    vector<vector<int>> queri(n+1);

    int q; cin >> q;
    vector<int> x(n), y(n);
    rep(i, 0, q){
        cin >> x[i] >> y[i];
    }    
    rep(i, 0, q){
        queri[x[i]].push_back(i);
    }

    
    
    return 0;
}