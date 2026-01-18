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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b; a--, b--;
        int w; cin >> w;
        g[a].push_back({b, w});
    }
    vector<vector<bool>> seen(n, vector<bool>(1<<10));
    seen[0][0] = true;
    queue<pair<int, int>> que;
    que.push({0, 0});
    while(!que.empty()){
        auto [q, s] = que.front(); que.pop();
        for(auto [nq, t]: g[q]){
            int w = (s^t);
            if(seen[nq][w]) continue;
            seen[nq][w] = true;
            que.push({nq, w});
        }
    }

    rep(i, 0, 1<<10){
        if(seen[n-1][i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;    
    
    return 0;
}