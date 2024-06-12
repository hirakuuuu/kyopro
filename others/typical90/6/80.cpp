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
包除原理
*/

int main(){
    int n, d; cin >> n >> d;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> dp(1<<n);
    ll ans = 1LL<<d;
    rep(i, 1, 1<<n){
        ll tmp = (1LL<<d)-1;
        rep(j, 0, n){
            if((i>>j)&1){
                tmp &= ((1LL<<d)-1)-a[j];
            }
        }
        int cnt = __popcount(tmp);
        if(__popcount(i)&1) ans -= 1LL<<cnt;
        else ans += 1LL<<cnt;
    }
    cout << ans << endl;


    return 0;
}