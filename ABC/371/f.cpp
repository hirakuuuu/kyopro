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

/*
x[i] -> x[i]-i としておくことで, 座標の管理が楽になる
- x[i] より右の箱の座標を全て -1 することで, 箱が棒（幅が0）になるイメージ
こうすると, 結局区間にある箱を全て座標 g に持っていくみたいな話にできる
これなら遅延セグ木
*/

int main(){
    int n; cin >> n;
    vector<ll> x(n+2);
    x[0] = -INF;
    rep(i, 1, n+1) cin >> x[i];
    x[n+1] = INF;

    set<tuple<int, int, ll>> s;
    for(int l = 0; l < n+2; ){
        int r = l+1;
        while(r < n+2 && x[r]-x[l] == r-l) r++;
        s.insert({l, r, x[l]});
        l = r;
    }

    // i 番目の高橋君の位置
    auto pos = [&](int i) -> ll {
        auto [l, r, start] = *prev(s.upper_bound({i, IINF, 0}));
        return start+(i-l);
    };




    ll ans = 0;
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        ll g; cin >> g;

        if(g < pos(t)){
            int ok = t, ng = 0;
            while(ok-ng > 1){
                int mid = (ok+ng)/2;
                if(g-(t-mid) <= pos(mid)) ok = mid;
                else ng = mid;
            }

            {
                auto [cl, cr, cstart] = *prev(s.upper_bound({t, IINF, 0}));
                if(cr != t+1){
                    s.erase({cl, cr, cstart});
                    s.insert({t+1, cr, cstart+(t+1-cl)});
                    s.insert({cl, t+1, cstart});
                }
            }
            {
                auto [cl, cr, cstart] = *prev(s.upper_bound({t, IINF, 0}));
                auto [pl, pr, pstart] = *prev(prev(s.upper_bound({t, IINF, 0})));
                while(ok < pr){
                    // 移動距離を計算
                    ans += (cstart-(pstart+pr-pl))*(cr-cl);
                    // 2つの区間をマージする
                    s.erase({cl, cr, cstart});
                    s.erase({pl, pr, pstart});
                    s.insert({pl, cr, pstart});
                    auto [_cl, _cr, _cstart] = *prev(s.upper_bound({t, IINF, 0}));
                    cl = _cl, cr = _cr, cstart = _cstart;
                    auto [_pl, _pr, _pstart] = *prev(prev(s.upper_bound({t, IINF, 0})));
                    pl = _pl, pr = _pr, pstart = _pstart;
                }
            }

            {
                // 最後の移動
                auto [cl, cr, cstart] = *prev(s.upper_bound({t, IINF, 0}));
                if(g < cstart+(t-cl)){
                    ans += (cstart+(t-cl)-g)*(cr-cl);
                    s.erase({cl, cr, cstart});
                    s.insert({cl, cr, g-(t-cl)});
                }
            }

        }else if(pos(t) < g){
            int ok = t, ng = n+1;
            while(ng-ok > 1){
                int mid = (ok+ng)/2;
                if(pos(mid) <= g+(mid-t)) ok = mid;
                else ng = mid;
            }

            {
                auto [cl, cr, cstart] = *prev(s.upper_bound({t, IINF, 0}));
                if(cl != t){
                    s.erase({cl, cr, cstart});
                    s.insert({t, cr, cstart+(t-cl)});
                    s.insert({cl, t, cstart});
                }
            }
            {
                auto [cl, cr, cstart] = *prev(s.upper_bound({t, IINF, 0}));
                auto [pl, pr, pstart] = *s.upper_bound({t, IINF, 0});
                while(pl <= ok){
                    // 移動距離を計算
                    ans += (pstart-(cstart+cr-cl))*(cr-cl);
                    // 2つの区間をマージする
                    s.erase({cl, cr, cstart});
                    s.erase({pl, pr, pstart});
                    s.insert({cl, pr, pstart-(cr-cl)});
                    auto [_cl, _cr, _cstart] = *prev(s.upper_bound({t, IINF, 0}));
                    cl = _cl, cr = _cr, cstart = _cstart;
                    auto [_pl, _pr, _pstart] = *s.upper_bound({t, IINF, 0});
                    pl = _pl, pr = _pr, pstart = _pstart;
                }
            }
            {
                // 最後の移動
                auto [cl, cr, cstart] = *prev(s.upper_bound({t, IINF, 0}));
                if(cstart+(t-cl) < g){
                    ans += (g-cstart-(t-cl))*(cr-cl);
                    s.erase({cl, cr, cstart});
                    s.insert({cl, cr, g-(t-cl)});
                }
            }
        }
        // cout << ans << endl;
        // for(auto [l, r, p]: s){
        //     cout << '[' << l << ' ' << r << "): " << p << endl; 
        // }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}