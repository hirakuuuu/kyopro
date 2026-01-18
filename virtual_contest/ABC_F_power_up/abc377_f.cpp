#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;
constexpr ll MOD = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m);
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    // a[i], b[i], a[i]+b[i], a[i]-b[i] がどれとも一致していないマスを数えたい
    

    ll ans = n*n;

    // 縦横で消えるやつ
    set<ll> sa, sb;
    rep(i, 0, m) sa.insert(a[i]);
    rep(i, 0, m) sb.insert(b[i]);
    ans -= sa.size()*n;
    ans -= sb.size()*n;
    ans += sa.size()*sb.size();
    // cout << ans << endl;

    auto f1 = [&](int x) -> int {
        if(x <= n-1) return x+1;
        return 2*n-1-x;
    };
    auto f2 = [&](int x) -> int {
        if(x <= 0) return n+x;
        return n-x;
    };
    // 斜めで消えるやつ
    {
        set<ll> seen1, seen2;
        rep(i, 0, m){
            if(!seen1.count(a[i]+b[i])){
                seen1.insert(a[i]+b[i]);
                ll l, r;
                if(a[i]+b[i] <= n-1) l = 0, r = a[i]+b[i];
                else l = a[i]+b[i]-(n-1), r = n-1;
                ll cnt1 = f1(a[i]+b[i]);
                set<ll> seen_;
                for(auto ssa: sa){
                    if(inr(0, a[i]+b[i]-ssa, n)){
                        seen_.insert(ssa);
                    }
                }
                for(auto ssb: sb){
                    if(inr(0, a[i]+b[i]-ssb, n)){
                        seen_.insert(a[i]+b[i]-ssb);
                    }
                }
                cnt1 -= seen_.size();
                ans -= cnt1;
            }
            if(!seen2.count(a[i]-b[i])){
                seen2.insert(a[i]-b[i]);
                ll cnt1 = f2(a[i]-b[i]);
                set<ll> seen_;
                for(auto ssa: sa){
                    if(inr(0, ssa-(a[i]-b[i]), n)){
                        seen_.insert(ssa);
                    }
                }
                for(auto ssb: sb){
                    if(inr(0, ssb+(a[i]-b[i]), n)){
                        seen_.insert(ssb+(a[i]-b[i]));
                    }
                }
                cnt1 -= seen_.size();
                ans -= cnt1;
            }
        }
    }
    // cout << ans << endl;

    // 斜めでの被りを消す
    set<pair<int, int>> p;
    rep(i, 0, m) rep(j, 0, m){
        if(i == j) continue;
        if((a[i]+b[i]+a[j]-b[j])%2 == 0 && (a[i]+b[i]-a[j]+b[j])%2 == 0){
            ll x = (a[i]+b[i]+a[j]-b[j])/2;
            ll y = (a[i]+b[i]-a[j]+b[j])/2;
            if(inr(0, x, n) && inr(0, y, n)){
                if(!sa.count(x) && !sb.count(y)) p.insert({x, y});
            }
        }
    }
    ans += p.size();
    cout << ans << endl;

    return 0;
}