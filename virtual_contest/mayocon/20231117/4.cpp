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
// 

int main(){
    int n, m; cin >> n >> m;
    vector<vector<tuple<int, ll, ll>>> g(n);
    rep(i, 0, m){
        int a, b;
        ll x, y; cin >> a >> b >> x >> y;
        a--, b--;
        g[a].push_back({b, x, y});
        g[b].push_back({a, -x, -y});
    }

    queue<int> que;
    que.push(0);
    vector<bool> seen(n);
    seen[0] = true;
    vector<pair<ll, ll>> ans(n);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto [nq, x, y]: g[q]){
            if(seen[nq]) continue;
            seen[nq] = true;
            ans[nq] = {ans[q].first+x, ans[q].second+y};
            que.push(nq);
        }
    }

    rep(i, 0, n){
        if(seen[i]){
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }else{
            cout << "undecidable" << endl;
        }
    }
    
    return 0;
}