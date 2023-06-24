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
// https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pll>> g(n+1);
    rep(i, 0, m){
        ll l, r, c; cin >> l >> r >> c;
        g[l].push_back({r, c});
    }

    priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push({0, 1});
    vector<ll> dist(n+1, -1);

    rep(i, 1, n+1){
        while(!que.empty()){
            pll q = que.top();
            if(q.second < i){
                que.pop();
                continue;
            }
            dist[i] = q.first;
            break;
        }
        if(dist[i] == -1)  continue;
        for(auto gg: g[i]){
            const auto [goal, cost] = gg;
            que.push({dist[i]+cost, goal});
        }
    }

    cout << dist[n] << endl;
    return 0;
}