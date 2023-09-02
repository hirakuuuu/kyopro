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
// https://atcoder.jp/contests/abc318/tasks/abc318_d

int main(){
    int n; cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, i+1, n){
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }

    vector<ll> dp((1<<n));
    rep(i, 0, (1<<n)){
        ll cnt = 0;
        vector<int> bit;
        rep(j, 0, n){
            if(i&(1<<j)) cnt++;
        }
        if(cnt%2) continue;
        rep(j, 0, n){
            rep(k, j+1, n){
                if((i&(1<<j)) > 0 && (i&(1<<k)) > 0){
                    chmax(dp[i], dp[i-(1<<j)-(1<<k)]+d[j][k]);
                }
            }
        }
    }

    if(n%2 == 0) cout << dp[(1<<n)-1] << endl;
    else{
        ll ans = 0;
        rep(i, 0, n){
            chmax(ans, dp[(1<<n)-1-(1<<i)]);
        }
        cout << ans << endl;
    }

   
    
    return 0;
}