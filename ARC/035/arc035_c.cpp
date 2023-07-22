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
// https://atcoder.jp/contests/arc035/tasks/arc035_c

int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, 1001001001));
    rep(i, 0, n) dist[i][i] = 0;
    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        chmin(dist[a][b], c);
        chmin(dist[b][a], c);
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                chmin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            ans += dist[i][j];
        }
    }

    int q; cin >> q;
    rep(k, 0, q){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        if(dist[a][b] > c){
            vector<vector<ll>> dist_ = dist;
            rep(i, 0, n){
                rep(j, 0, n){
                    if(dist[i][j] > min(dist[i][a]+c+dist[b][j], dist[i][b]+c+dist[a][j])){
                        dist_[i][j] = min(dist[i][a]+c+dist[b][j], dist[i][b]+c+dist[a][j]);
                        if(i < j) ans -= dist[i][j] - dist_[i][j];
                    }
                }
            }
            dist = dist_;
        }
        cout << ans << endl;
    }
    
    return 0;
}