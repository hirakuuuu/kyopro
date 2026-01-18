#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;


#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define ull unsigned long long 


// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ull d1[200005];
ull d2[200005];

int main(){
    int n; cin >> n;
    vector<vector<int>> g1(n), g2(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    
    ull ans = 0;
    rep(i, 0, n){
        rep(j, 0, n) d1[j] = d2[j] = 0;
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g1[q]){
                if(nq == i || d1[nq]) continue;
                d1[nq] = d1[q]+1;
                que.push(nq);
            }
        }
        que.push(i);
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g2[q]){
                if(nq == i || d2[nq]) continue;
                d2[nq] = d2[q]+1;
                que.push(nq);
            }
        }

        rep(j, 0, n) ans += d1[j]*d2[j];
    }
    cout << ans << endl;

    return 0;
}