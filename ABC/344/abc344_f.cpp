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
// https://atcoder.jp/contests/abc344/tasks/abc344_f

// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(ll s, vector<vector<pll>> &g){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(g.size(), (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    int n; cin >> n;
    vector<vector<ll>> p(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> p[i][j];
        }
    }
    vector<vector<ll>> r(n, vector<ll>(n-1));
    rep(i, 0, n){
        rep(j, 0, n-1){
            cin >> r[i][j];
        }
    }
    vector<vector<ll>> d(n-1, vector<ll>(n));
    rep(i, 0, n-1){
        rep(j, 0, n){
            cin >> d[i][j];
        }
    }
    
    vector<int> P(n*n);
    rep(i, 0, n){
        rep(j, 0, n){
            P[i*n+j] = p[i][j];
        }
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    map<int, int> id;
    int ii = 0;
    for(auto pp: P) id[pp] = ii++;

    vector<vector<vector<pair<ll, ll>>>> dp(n, vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>(P.size(), {INF, INF})));
    dp[0][0][id[p[0][0]]] = {0, 0};
    rep(i, 0, n){
        rep(j, 0, n){
            if(i < n-1){
                rep(k, 0, P.size()){
                    ll tmp = max(0LL, (d[i][j]+dp[i][j][k].second+P[k]-1)/P[k]);
                    chmin(dp[i+1][j][max(id[p[i+1][j]], k)], make_pair(dp[i][j][k].first+tmp, -(-dp[i][j][k].second+P[k]*tmp-d[i][j])));
                }
            }
            if(j < n-1){
                rep(k, 0, P.size()){
                    ll tmp = max(0LL, (r[i][j]+dp[i][j][k].second+P[k]-1)/P[k]);
                    chmin(dp[i][j+1][max(id[p[i][j+1]], k)], make_pair(dp[i][j][k].first+tmp, -(-dp[i][j][k].second+P[k]*tmp-r[i][j])));
                }
            }
        }
    }

    ll ans = INF;
    rep(j, 0, P.size()) chmin(ans, dp[n-1][n-1][j].first);
    cout << ans+2*n-2 << endl;
    
    return 0;
}