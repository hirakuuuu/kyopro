#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc257/tasks/abc257_d

int main(){
    int n; cin >> n;
    vector<ll> x(n), y(n), p(n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> p[i];
    vector<vector<ll>> dist(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            if((abs(x[i]-x[j])+abs(y[i]-y[j]))%p[i]){
                dist[i][j] = (abs(x[i]-x[j])+abs(y[i]-y[j]))/p[i]+1;
            }else{
                dist[i][j] = (abs(x[i]-x[j])+abs(y[i]-y[j]))/p[i];
            }
        }
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
            }
        }
    }
    ll ans = (1LL<<60);

    rep(i, 0, n){
        ll max_s = 0;
        rep(j, 0, n){
            max_s = max(max_s, dist[i][j]);
        }
        ans = min(ans, max_s);
    }
    cout << ans << endl;

    return 0;
}