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

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--, y--;
        g[y].push_back(x);
    }

    int Q; cin >> Q;
    vector<int> check(n);
    queue<int> que;
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int v; cin >> v; v--;
            if(check[v]) continue;
            que.push(v);
            check[v] = 1;
            while(!que.empty()){
                int q = que.front(); que.pop();
                for(auto nq: g[q]){
                    if(check[nq]) continue;
                    que.push(nq);
                    check[nq] = 1;
                }
            }
        }else{
            int v; cin >> v; v--;
            if(check[v]) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
    
    return 0;
}