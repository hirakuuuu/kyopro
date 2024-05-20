#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const long double pi = 3.14159265358979;

/*
偏角がどの範囲かが全然わかってない
ライブラリを作る
*/

int main(){
    ll n; cin >> n;
    vector<ll> a(2*n);
    rep(i, 0, 2*n) cin >> a[i];

    vector<vector<ll>> dp(2*n+1, vector<ll>(2*n+1, 1e10));
    rep(i, 0, 2*n+1) dp[i][i] = 0; 
    for(ll k = 2; k <= 2*n; k += 2){
        rep(i, 0, 2*n){
            if(i+k > 2*n) break;
            rep(j, i+1, i+k){
                chmin(dp[i][i+k], abs(a[i]-a[j])+dp[i+1][j]+dp[j+1][i+k]);
            }
        }
    }
    cout << dp[0][2*n] << endl;
    



    return 0;
}