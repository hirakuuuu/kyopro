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
    int n, d; cin >> n >> d;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<ll> acc_x(n+1), acc_y(n+1);
    rep(i, 0, n) acc_x[i+1] = acc_x[i]+x[i];
    rep(i, 0, n) acc_y[i+1] = acc_y[i]+y[i];
    auto dist_x = [&](ll px) -> ll {
        ll res = 0;
        int pos = lower_bound(x.begin(), x.end(), px)-x.begin();
        res += px*pos-acc_x[pos];
        res += (acc_x[n]-acc_x[pos])-px*(n-pos);
        return res;
    };
    auto dist_y = [&](ll py) -> ll {
        ll res = 0;
        int pos = lower_bound(y.begin(), y.end(), py)-y.begin();
        res += py*pos-acc_y[pos];
        res += (acc_y[n]-acc_y[pos])-py*(n-pos);
        return res;
    };

    // 最小値をとる y の範囲
    ll min_dy = INF;
    rep(cy, -2000005, 2000005) chmin(min_dy, dist_y(cy));
    ll ly = INF, ry = -INF;
    rep(cy, -2000005, 2000005){
        if(dist_y(cy) == min_dy){
            chmin(ly, cy);
            chmax(ry, cy);
        }
    }

    ll ans = 0;
    rep(cx, -2000005, 2000005){
        ll tmp = dist_x(cx);
        if(tmp > d) continue;
        ll rest = d-tmp;
        if(min_dy > rest) continue;
        // dist_y(cy) <= rest となる y の範囲を求める
        ll ok = ly, ng = -2000005;
        while(ok-ng > 1){
            ll mid = (ok+ng)/2;
            if(dist_y(mid) > rest) ng = mid;
            else ok = mid;
        }
        ans += (ly-ok);

        ok = ry, ng = 2000005;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if(dist_y(mid) > rest) ng = mid;
            else ok = mid;
        }
        ans += (ok-ry);

        ans += ry-ly+1; 
    }
    cout << ans << endl;
    return 0;
}