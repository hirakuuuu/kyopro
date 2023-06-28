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



int main(){
    ll n, k; cin >> n >> k;
    vector<ll> l(k), r(k);
    rep(i, 0, k) cin >> l[i] >> r[i];

    vector<ll> dp(n+10);
    dp[1] = 1;
    rep(i, 1, n){
        rep(j, 0, k){
            dp[min(n+5, i+l[j])] += dp[i];
            dp[min(n+5, i+l[j])] %= MOD;
            dp[min(n+5, i+r[j]+1)] += MOD-dp[i];
            dp[min(n+5, i+r[j]+1)] %= MOD;
        }
        dp[i+1] += dp[i];
        dp[i+1] %= MOD;
    }

    cout << (dp[n]-dp[n-1]+MOD)%MOD << endl;
    
    return 0;
}