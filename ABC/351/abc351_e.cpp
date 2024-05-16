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
絶対値の差の大きい方を距離とするのはチェビシェフ距離
45度回転させて、座標軸を sqrt(2) 倍すると、斜め移動を上下左右の移動に変換できるので、マンハッタン距離になる
*/


int main(){
    int n; cin >> n;
    vector<ll> x(n), y(n);
    vector<ll> X(n), Y(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        X[i] = x[i]-y[i];
        Y[i] = x[i]+y[i];
    }
    swap(X, x);
    swap(Y, y);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<ll> sum(2), cnt(2);
    ll ans = 0;
    rep(i, 0, n){
        int f = x[i]%2;
        if(f < 0) f += 2;
        ans += x[i]*cnt[f]-sum[f];
        sum[f] += x[i];
        cnt[f]++;
    }
    sum[0] = sum[1] = 0;
    cnt[0] = cnt[1] = 0;
    rep(i, 0, n){
        int f = y[i]%2;
        if(f < 0) f += 2;
        ans += y[i]*cnt[f]-sum[f];
        sum[f] += y[i];
        cnt[f]++;
    }

    cout << ans/2 << endl;
    return 0;
}