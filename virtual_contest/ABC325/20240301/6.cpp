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
    vector<ll> d(n);
    rep(i, 0, n) cin >> d[i];
    vector<ll> l(2), c(2), k(2);
    rep(i, 0, 2) cin >> l[i] >> c[i] >> k[i];

    vector<ll> dp(k[0]+1, k[1]); // センサー1をi個使用済みで、残せるセンサー2の個数の最大値
    rep(i, 0, n){
        vector<ll> dp_(k[0]+1, -1);
        vector<ll> need(k[0]+1); // センサ1をi個使うときに必要なセンサ2の個数
        rep(j, 0, k[0]+1){
            ll rest = max(0LL, d[i]-l[0]*j);
            need[j] = (rest+l[1]-1)/l[1];
        }
        rep(j, 0, k[0]+1){
            rep(m, 0, j+1){
                chmax(dp_[j], dp[j-m]-need[m]);
            }
        }
        swap(dp, dp_);
    }
    ll ans = INF;
    rep(i, 0, k[0]+1){
        if(dp[i] >= 0){
            chmin(ans, i*c[0]+(k[1]-dp[i])*c[1]);
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    
    return 0;
}