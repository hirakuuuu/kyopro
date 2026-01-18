
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
constexpr ll MOD = 4736947;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, x; cin >> n >> x;

    int offset = n*3;
    vector<ll> dp(n*3*2+1);
    dp[0+offset] = 1;
    vector<ll> ndp(n*3*2+1);

    rep(i, 0, n){
        rep(j, -(i+1)*3, (i+1)*3+1){
            ndp[j+offset] = 0;
        }

        int k; cin >> k;
        vector<ll> s(7);
        rep(j, 0, k){
            int t; cin >> t;
            s[t+3]++;
        }

        rep(j, 0, 7){
            if(s[j] == 0) continue;
            rep(l, -i*3, i*3+1){
                ndp[l+j-3+offset] = (ndp[l+j-3+offset]+(dp[l+offset]*s[j]))%MOD;
            }
        }
        swap(dp, ndp);
    }
    
    ll ans = 0;
    chmax(x, -offset);
    rep(i, x+offset, n*2*3+1){
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}