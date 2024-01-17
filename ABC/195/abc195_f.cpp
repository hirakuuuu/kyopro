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
// https://atcoder.jp/contests/abc195/tasks/abc195_f

const vector<ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
const int n = 20;

int main(){
    ll a, b; cin >> a >> b;
    vector<ll> c(b-a+1);
    vector<int> bit(b-a+1);
    rep(i, 0, b-a+1){
        c[i] = a+i;
        rep(j, 0, n){
            if(c[i]%p[j] == 0){
                bit[i] += (1<<j);
            }
        }
    }

    vector<ll> dp(1<<n);
    dp[0] = 1;
    rep(i, 0, b-a+1){
        vector<ll> dp_ = dp;
        rep(j, 0, 1<<n){
            if((bit[i]&j) == 0) dp_[bit[i]+j] += dp[j];
        }
        swap(dp, dp_);
    }

    ll ans = 0;
    rep(i, 0, 1<<n){
        ans += dp[i];
    }
    cout << ans << endl;



    
    return 0;
}