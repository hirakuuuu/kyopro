#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// sを始点とする各頂点への距離の最小値を格納した配列を返す
// 最短路を求める過程で

ll dist_s[100005], dist_t[100005];
mint cnt_s[100005], cnt_t[100005];

void dijk(int s, vector<vector<pair<ll, ll>>> &g, auto &dist, auto &cnt){
    rep(i, 0, 100005) dist[i] = INF;
    rep(i, 0, 100005) cnt[i] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    que.push(make_pair(0, s));
    dist[s] = 0;
    cnt[s] = 1;
    while(!que.empty()){
        pair<ll, ll> q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                cnt[v] = cnt[u];
                que.push({dist[v], v});
            }else if(dist[v] == d+cost){
                cnt[v] += cnt[u];
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    int S, T; cin >> S >> T; S--, T--;
    vector<int> u(m), v(m);
    vector<ll> w(m);
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, 0, m){
        cin >> u[i] >> v[i] >> w[i]; u[i]--, v[i]--;
        g[u[i]].push_back({v[i], w[i]});
        g[v[i]].push_back({u[i], w[i]});
    }
    dijk(S, g, dist_s, cnt_s);
    dijk(T, g, dist_t, cnt_t);

    mint ans = cnt_s[T]*cnt_s[T];
    ll dist_st = dist_s[T];
    // 余事象を除いていく
    // 頂点でぶつかる場合
    if(dist_st%2 == 0){
        rep(i, 0, n){
            if(dist_s[i] == dist_st/2 && dist_t[i] == dist_st/2){
                // 頂点 i でぶつかるパターンを引く
                mint tmp = cnt_s[i]*cnt_t[i]; // i を通るような最短路の個数
                ans -= tmp*tmp;
            }
        }
    }
    // 辺でぶつかる場合（ちょうど頂点にのる場合は含まない）
    rep(i, 0, m){
        if(dist_s[u[i]] > dist_s[v[i]]) swap(u[i], v[i]);
        if(dist_s[u[i]]+w[i]+dist_t[v[i]] == dist_st){ // 辺 i を通る最短路が存在することの判定
            if(dist_s[u[i]] < (dist_st+1)/2 && dist_st/2 < dist_s[v[i]]){ // 辺 i でぶつかる場合
                mint tmp = cnt_s[u[i]]*cnt_t[v[i]];
                ans -= tmp*tmp;
            }
        }
    }
    cout << ans.val() << endl;

    
    return 0;
}