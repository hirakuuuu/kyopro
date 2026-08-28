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
    int n, Q; cin >> n >> Q;
    vector<int> par(2*n, -1);
    rep(i, n, 2*n){
        par[i] = i-n;
    }
    while(Q--){
        int c, p; cin >> c >> p; c--, p--;
        c += n, p += n;
        par[c] = p;
    }

    vector<vector<int>> g(2*n);
    rep(i, n, 2*n){
        g[par[i]].push_back(i);
    }

    vector<int> ans(n);
    vector<int> seen(2*n);
    rep(i, 0, n){
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(seen[nq]) continue;
                seen[nq] = 1;
                ans[i]++;
                que.push(nq);
            }
        }
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}