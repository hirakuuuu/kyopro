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
    int t; cin >> t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        rep(i, 0, n){
            ll x = lcm(b[i], k)/b[i];
            b[i] *= x;
            a[i] *= x;
        }
        vector<ll> dp(m+1);
        dp[0] = 1;
        rep(i, 0, n){
            rep(j, 0, m+1){
                if(j+a[i] <= m && dp[j]) dp[j+a[i]] = 1;
            }
        }

        if(dp[m]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}