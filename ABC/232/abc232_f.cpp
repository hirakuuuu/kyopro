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
// https://atcoder.jp/contests/abc232/tasks/abc232_f

int main(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<ll> dp(1<<n, 9e18);
    dp[0] = 0;
    rep(i, 0, 1<<n){
        ll tmp = 0;
        rep(j, 0, n) tmp += (i&(1<<j)) > 0;

        ll cnt = tmp;
        rep(j, 0, n){
            if((i&(1<<j)) > 0){
                cnt--;
            }else{
                chmin(dp[i+(1<<j)], dp[i]+abs(a[j]-b[tmp])*x+cnt*y);
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;

    
    return 0;
}