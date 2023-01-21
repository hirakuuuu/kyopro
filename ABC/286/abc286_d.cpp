#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc286/tasks/abc286_d

ll dp[105][100005];

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];
    dp[0][0] = 1;
    rep(i, 1, n+1){
        rep(j, 0, b[i]+1){
            rep(k, 0, x+1){
                dp[i][k+j*a[i]] |= dp[i-1][k];
            }
        }
    }

    if(dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}