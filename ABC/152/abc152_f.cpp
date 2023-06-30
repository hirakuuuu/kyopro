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
// https://atcoder.jp/contests/abc152/tasks/abc152_f

int main(){
    int n; cin >> n;
    vector<int> a(n-1), b(n-1);
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    
    vector<vector<int>> dist(n, vector<int>(n, IINF));
    rep(i, 0, n) dist[i][i] = 0;
    rep(i, 0, n){
        for(auto j: g[i]){
            dist[i][j] = 1;
        }
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                chmin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    int m; cin >> m;
    vector<int> point(n-1);
    vector<int> u(m), v(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        rep(j, 0, n-1){
            bool f1 = (dist[u[i]][a[j]] + dist[a[j]][v[i]] == dist[u[i]][v[i]]);
            bool f2 = (dist[u[i]][b[j]] + dist[b[j]][v[i]] == dist[u[i]][v[i]]);
            if(f1 && f2){
                point[j] += (1<<i);
            }
        }
    }

    vector<vector<ll>> dp(n, vector<ll>((1<<m), 0));
    dp[0][0] = 1;
    rep(i, 0, n-1){
        rep(j, 0, (1<<m)){
            dp[i+1][j] += dp[i][j];
            dp[i+1][(j|point[i])] += dp[i][j];
        }
    }

    cout << dp[n-1][(1<<m)-1] << endl;

    
    return 0;
}