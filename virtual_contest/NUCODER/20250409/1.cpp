#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, x, y; cin >> n >> x >> y; x--, y--;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n, -1);
    queue<int> que;
    vector<bool> seen(n);
    que.push(x);
    seen[x] = true;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(seen[nq]) continue;
            seen[nq] = true;
            par[nq] = q;
            que.push(nq);
        }
    }

    vector<int> ans;
    int pos = y;
    ans.push_back(y);
    while(par[pos] != -1){
        pos = par[pos];
        ans.push_back(pos);
    }
    reverse(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa+1 << ' ';
    }
    cout << endl;    
    return 0;
}
