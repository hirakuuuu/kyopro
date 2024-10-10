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
コードと別の方針
- \sum{A} が 0 でないとだめ
- A の累積和に対する操作を考えると, その総和が mod n で変化しない
- つまり, 累積和の総和が n の倍数で無いとダメ
- また, 累積和の総和が 0 でないとき, +n or -n で総和を 0 にする必要がある 
- その後, 値が正のところから後ろにずらしてくイメージで操作する（円環状で実装すると分かりやすい）

参考: https://atcoder.jp/contests/arc129/submissions/27425702
*/

int main(){
    ll n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    // 合計 0 でないと達成不可能
    ll sum_a = 0;
    rep(i, 1, n+1) sum_a += a[i];
    if(sum_a != 0){
        cout << -1 << endl;
        return 0;
    }

    vector<ll> x(n+2); // i に対して操作を行う回数 x[0] = x[n], x[n+1] = x[1]
    vector<ll> y(n+2); // y[i] := x[i+1]-x[i]
    // y[i]-y[i-1] := a[i];
    vector<ll> z(n+2); // z[i] = y[i]-y[1]
    z[1] = 0;
    rep(i, 2, n+1){
        z[i] = z[i-1]+a[i];
    }
    // \sum{y} = 0 かつ \sum{z} = \sum{y}-n*y[1] = -n*y[1] より y[1] が特定できる
    ll sum_z = 0;
    rep(i, 1, n+1) sum_z += z[i];
    if(sum_z%n != 0){
        cout << -1 << endl;
        return 0;
    }
    // y[i] が特定できる
    y[1] = -sum_z/n;
    rep(i, 2, n+1) y[i] = a[i]+y[i-1];
    
    vector<ll> w(n+2); // w[i] := x[i]-x[1];
    w[1] = 0;
    rep(i, 2, n+1) w[i] = w[i-1]+y[i-1];
    
    // x[1] の最小値を特定する
    ll mx = 0;
    rep(i, 2, n+1){
        // x[i] >= 0 より x[1] >= -w[i];
        chmax(mx, -w[i]);
    }
    x[1] = mx;
    rep(i, 2, n+1) x[i] = w[i]+x[1];

    ll ans = 0;
    rep(i, 1, n+1) ans += x[i];
    cout << ans << endl;




    return 0;
}