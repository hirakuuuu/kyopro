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
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> g(n);
        rep(i, 0, m){
            int u, v; cin >> u >> v; u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll sum = 0;
        vector<ll> b(n);
        rep(i, 0, n){
            cin >> b[i];
            sum += b[i];
        }
        if(k%2 == 0 && sum%2 == 1){
            cout << "No" << endl;
            continue;
        }

        vector<int> col(n, -1);
        queue<int> que;
        que.push(0);
        col[0] = 0;
        bool bi = true;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(col[nq] != -1){
                    if(col[q] != col[nq]) continue;
                    bi = false;
                }else{
                    col[nq] = 1-col[q];
                    que.push(nq);
                }
            }
        }
        if(!bi){
            cout << "Yes" << endl;
        }else{
            vector<ll> tot(2);
            rep(i, 0, n){
                tot[col[i]] += b[i];
            }
            if(tot[0]%k == tot[1]%k) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    
    return 0;
}