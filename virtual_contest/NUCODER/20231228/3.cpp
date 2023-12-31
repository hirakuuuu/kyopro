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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<string> s(n);
    vector<vector<pair<ll, ll>>> dist(n, vector<pair<ll, ll>>(n, {1e18, 1e18}));
    rep(i, 0, n){
        cin >> s[i];
        dist[i][i] = {1, -a[i]};
        rep(j, 0, n){
            if(s[i][j] == 'Y') dist[i][j] = {2, -a[i]-a[j]};
        }
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                pair<ll, ll> tmp =  {dist[i][k].first+dist[k][j].first-1, dist[i][k].second+dist[k][j].second+a[k]}; 
                chmin(dist[i][j], tmp);
            }
        }
    }
    int q; cin >> q;
    pair<ll, ll> init = {1e18, 1e18};
    while(q--){
        int u, v; cin >> u >> v;
        u--, v--;
        if(dist[u][v] == init){
            cout << "Impossible" << endl;
        }else{
            cout << dist[u][v].first-1 << ' ' << -dist[u][v].second << endl;
        }
    }


    
    return 0;
}