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
// https://atcoder.jp/contests/abc051/tasks/abc051_d

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, IINF));
    rep(i, 0, n) dist[i][i] = 0;
    vector<ll> a(m), b(m), c(m);
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        chmin(dist[a[i]][b[i]], c[i]);
        chmin(dist[b[i]][a[i]], c[i]);
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                chmin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, 0, m){
        rep(j, 0, n){
            if(j == a[i] || j == b[i]) continue;
            if(dist[a[i]][j]+dist[j][b[i]] < c[i]){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}