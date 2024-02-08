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
// https://atcoder.jp/contests/arc169/tasks/arc169_b

int main(){
    ll n, s; cin >> n >> s;
    vector<ll> a(n), acc(n+1);
    rep(i, 0, n){
        cin >> a[i];
        acc[i+1] = acc[i]+a[i];
    }
    vector<ll> r(n);
    rep(i, 1, n){
        if(acc[i+1] > s){
            r[0] = i-1;
            break;
        }
        if(r[0] == 0) r[0] = n-1;
    }
    rep(i, 1, n){
        rep(j, r[i-1], n){
            if(acc[j+1]-acc[i] > s){
                r[i] = j-1;
                break;
            }
        }
        if(r[i] == 0) r[i] = n-1;
    }

    vector<ll> dp(n+1);
    dp[n-1] = 1;
    rrep(i, n-2, 0){
        dp[i] = (n-i)+dp[r[i]+1];
    }
    ll ans = 0;
    rep(i, 0, n){
        ans += dp[i];
    }
    cout << ans << endl;
    
    return 0;
}