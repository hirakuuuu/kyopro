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
// https://atcoder.jp/contests/arc064/tasks/arc064_c


// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<double> dijk(int s, vector<vector<pair<double, ll>>> &g){
    priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> que;
    vector<double> dist(100005, 9e18);
    que.push(make_pair(0.0, s));
    dist[s] = 0;
    while(!que.empty()){
        pair<double, ll> q = que.top(); que.pop();
        double d = q.first;
        ll u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            double cost = nq.first;
            ll v = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    ll xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    int n; cin >> n;
    vector<ll> x(n+2), y(n+2);
    vector<double> r(n+2);
    x[0] = xs;
    y[0] = ys;
    x[n+1] = xt;
    y[n+1] = yt;
    rep(i, 1, n+1) cin >> x[i] >> y[i] >> r[i];

    vector<vector<double>> dist(n+2, vector<double>(n+2));
    rep(i, 0, n+2){
        rep(j, 0, n+2){
            dist[i][j] = max(0.0, sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j]);
        }
    }

    vector<vector<pair<double, ll>>> g(n+2);
    rep(i, 0, n+2){
        rep(j, i+1, n+2){
            g[i].push_back({dist[i][j], j});
            g[j].push_back({dist[j][i], i});
        }
    }

    vector<double> ans = dijk(0, g);
    printf("%.10f\n", ans[n+1]);

    return 0;
}