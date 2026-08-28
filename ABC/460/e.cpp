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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll len = 0;
        {
            ll _n = n;
            while(_n){
                len++;
                _n /= 10;
            }
        }
        ll ten = 1;
        mint ans = 0;
        rep(k, 1, len+1){
            ll cnt = min(ten*9, n-ten+1);
            __int128_t l = 1;
            rep(_, 0, k) l *= 10;
            ll g = gcd(l-1, m);
            ans += mint(n/(m/g))*cnt;
            if(k != len) ten *= 10;
        }
        cout << ans.val() << endl;

    }
    return 0;
}