#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc198/tasks/abc198_e

vector<int> g[100005];
int c[100005], good[100005], dist[100005], color[100005];

void dfs(int s){
    if(color[c[s]] == 0) good[s] = 1;
    color[c[s]]++;
    for(auto ns: g[s]){
        if(dist[ns] >= 0) continue;
        dist[ns] = dist[s]+1;
        dfs(ns);
    }
    color[c[s]]--;
}


int main(){
    int n; cin >> n;
    rep(i, 1, n+1) cin >> c[i];
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i, 1, n+1) dist[i] = -1;

    dist[1] = 0;
    dfs(1);

    rep(i, 1, n+1){
        if(good[i]) cout << i << endl;
    }
    

    
    return 0;
}