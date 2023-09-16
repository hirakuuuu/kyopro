#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc320/tasks/abc320_d

int main(){
    int n, m; cin >> n >> m;
    vector<vector<tuple<ll, ll, ll>>> g(n);
    rep(i, 0, m){
        ll a, b, x, y; cin >> a >> b >> x >> y;
        a--, b--;
        g[a].push_back({b, x, y});
        g[b].push_back({a, -x, -y});
    }

    vector<pair<ll, ll>> ans(n);
    vector<bool> seen(n);
    queue<ll> que;
    que.push(0);
    seen[0] = true;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto ng: g[q]){
            auto [nq, x, y] = ng;
            if(seen[nq]) continue;
            ans[nq] = {ans[q].first+x, ans[q].second+y};
            seen[nq] = true;
            que.push(nq);
        }
    }
    
    rep(i, 0, n){
        if(!seen[i]) cout << "undecidable" << '\n';
        else cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}