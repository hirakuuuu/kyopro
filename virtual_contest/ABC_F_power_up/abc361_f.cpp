#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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


int main(){
    ll n; cin >> n;
    ll ans = 0;
    // 2 乗は二分探索
    {
        ll ok = 1, ng = IINF;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if(mid*mid <= n) ok = mid;
            else ng = mid;
        }
        ans += ok;
    }
    // cout << ans << endl;

    auto is_small = [&](ll x, ll p, int e) -> bool { // p^e <= x の判定
        while(e--){
            x /= p;
        }
        return (x > 0);
    };
    set<ll> s;
    // 4 乗以上は全探索
    rep(x, 2, 1000001){
        int sx = (int)sqrt(x);
        if(sx*sx == x) continue;
        rep(b, 3, 60){
            if(b%2 == 0) continue;
            if(!is_small(n, x, b)) break;
            ll tmp = 1;
            rep(j, 0, b) tmp *= x;
            s.insert(tmp);
        }
    }
    ans += s.size();
    cout << ans << endl;
    
    return 0;
}