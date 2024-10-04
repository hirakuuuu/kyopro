#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n);
    vector<ll> acc(n+1);
    rep(i, 0, n){
        cin >> a[i];
        acc[i+1] = acc[i]+a[i];
    }

    vector<mint> dp(n+1);
    map<ll, mint> cnt;
    mint sum = 1;
    dp[0] = 1;
    cnt[0] = 1;
    rep(i, 1, n+1){
        dp[i] = mint(sum)-(cnt[acc[i]-k]);
        sum += dp[i];
        cnt[acc[i]] += dp[i];
    }
    cout << dp[n].val() << endl;

    
    return 0;
}