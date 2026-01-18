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
    int n; cin >> n;
    vector<ll> a(n), acc(n+1);
    ll tot = 0;
    rep(i, 0, n){
        cin >> a[i];
        tot += a[i];
        acc[i+1] = acc[i]+a[i];
    }
    ll b, cnt;
    if(tot >= 0){
        b = tot/n;
        cnt = tot%n;
    }else{
        b = (tot-n+1)/n;
        cnt = (n-(b*n-tot)%n)%n;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(cnt+1, INF));
    dp[0][0] = 0;
    rep(i, 1, n+1){
        rep(j, 0, cnt+1){
            if(dp[i-1][j] == INF) continue;
            if(j > i || j+(n-i+1) < cnt) continue;

            ll tmp = a[i-1]+(acc[i-1]-(j+b*(i-1)));
            chmin(dp[i][j], dp[i-1][j]+abs(tmp-b));
            if(j < cnt) chmin(dp[i][j+1], dp[i-1][j]+abs(tmp-(b+1)));
        }
    }

    cout << dp[n][cnt] << endl;
    
    return 0;
}