#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc277/tasks/abc277_c

map<int, vector<int>> m;
map<int, bool> seen;

int dfs(int s){
    int res = s;
    seen[s] = true;
    for(auto &ns: m[s]){
        if(seen[ns]) continue;
        res = max(res, dfs(ns));
    }
    return res;
}

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }

    cout << dfs(1) << endl;


    
    return 0;
}