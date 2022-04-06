#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc137/tasks/abc137_e

int n, m, p;
vector<vector<int>> g(2505, vector<int>(2505, -1));
void dfs(int pos, int cnt){
    rep(i, 1, n+1){
        
    }

    

}

int main(){
    cin >> n >> m >> p;
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = c-p;
    }

    

    
    return 0;
}