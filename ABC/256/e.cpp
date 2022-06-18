#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc256/tasks/abc256_e

vector<vector<int>> g(200005);
vector<int> c(200005);

vector<int> par(200005, -1);

int root(int x){
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}

bool same(int x, int y){
    return root(x) == root(y);
}

int size(int x){
    x = root(x);
    return (-1)*par[x];
}

void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(size(x) < size(y)) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int dfs(int start, int pos, int goal, set<int> &s){
    int res = MOD;

    for(auto ns: g[pos]){
        s.insert(c[ns]);
        if(ns == start){
            return *s.begin();
        }
        res = min(res, dfs(start, ns, goal, s));
        s.erase(c[ns]);
    }
    
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> x(n);
    vector<pii> cycle;
    rep(i, 0, n){
        cin >> x[i];
        g[x[i]].push_back(i+1);
        if(same(x[i], i+1)) cycle.push_back({x[i], i+1});
        else unite(x[i], i+1);
    }
    rep(i, 0, n) cin >> c[i+1];

    ll ans = 0;
    for(auto cy: cycle){
        set<int> s;
        ans += dfs(cy.first, cy.first, cy.second, s);
    }
    cout << ans << endl;




    
    return 0;
}