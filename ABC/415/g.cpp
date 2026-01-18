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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n; cin >> n;
    int m; cin >> m;
    vector<int> c(301);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        chmax(c[a], b);
    }

    vector<ll> dp(300*300+1);
    // rep(i, 0, 300*300+1) dp[i] = i;
    rep(i, 0, 300*300+1){
        rep(j, 0, 301){
            if(i >= j) chmax(dp[i], dp[i-j+c[j]]+c[j]);
        }
    }

    if(n <= 300*300){
        cout << n+dp[n] << endl;
        return 0;
    }

    int p = 0, q = 1;
    rep(j, 1, 301){
        if(p*(j-c[j]) < c[j]*q){
            p = c[j];
            q = j-c[j];
        }
    }

    ll ans = n;
    ll cnt = (n-300*300)/q+1;
    n -= q*cnt;
    ans += p*cnt;
    ans += dp[n];
    cout << ans << endl;    

    return 0;
}