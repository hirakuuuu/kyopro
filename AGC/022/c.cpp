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

/*
２回同じ操作を行う必要はない（同じ数字に２回同じ操作を行っても意味がないため）
また、kができるだけ小さい方がうれしい.
大きい方から使わなければならない数を固定していくことを考える.
*/


int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll ans = (1LL<<50)-2;
    rrep(k, 49, 1){
        ans ^= (1LL<<k);
        bool ok = true;
        rep(i, 0, n){
            vector<int> dp(55, 0);
            dp[a[i]] = 1;
            rrep(j, 50, 1){
                if(((ans>>j)&1) == 0) continue;
                rep(l, 0, 51){
                    if(dp[l]) dp[l%j] = 1;
                }
            }
            if(!dp[b[i]]) ok = false;
        }
        if(!ok) ans ^= (1LL<<k);
    }

    bool ok = true;
    rep(i, 0, n){
        vector<int> dp(55, 0);
        dp[a[i]] = 1;
        rrep(j, 50, 1){
            if(((ans>>j)&1) == 0) continue;
            rep(l, 0, 51){
                if(dp[l]) dp[l%j] = 1;
            }
        }
        if(!dp[b[i]]) ok = false;
    }
    if(ok) cout << ans << endl;
    else cout << -1 << endl;

    


    
    return 0;
}