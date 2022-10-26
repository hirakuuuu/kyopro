#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_cj


vector<int> a(100);
vector<vector<int>> g(100);

int dfs(int s){
    int res = a[s];
    for(auto ns: g[s]){
        res += dfs()

    }
}

int main(){
    int n, q; cin >> n >> q;
    rep(i, 1, n+1) cin >> a[i];
    
    vector<vector<int>> able(n+1, vector<int>(n+1, 1));
    rep(i, 0, q){
        int x, y; cin >> x >> y;
        able[x][y] = 0;
    }

    rep(i, 1, n+1){
        rep(j, i+1, n+1){
            if(able[i][j]){
                g[i].push_back(j);
            }
        }
    }

    rep(i, 1, 8889){
        
    }


    
    return 0;
}