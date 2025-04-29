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

int main(){
    int n; cin >> n;
    vector<int> x(n), h(n);
    rep(i, 0, n){
        cin >> x[i] >> h[i];
    }

    // (x1, y1), (x2, y2) を通る直線に対して，(p, q) が隠れるかどうか
    auto is_beyond = [&](ll x1, ld y1, ll x2, ll y2, ll p, ll q) -> bool {
        if(x2-p == 0){
            return x2*q-y2*p <= 0;
        }else if(x2-p > 0){
            return (ld)(x2*q-y2*p)/(x2-p) <= y1;
        }
        return (ld)(x2*q-y2*p)/(x2-p) >= y1;
    };
    // 座標 0 から見えるかどうか
    bool flag = true;
    rep(i, 1, n){
        if(is_beyond(0, 0, x[i-1], h[i-1], x[i], h[i])){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << -1 << endl;
        return 0;
    }

    // 二分探索
    ld ok = 1e18+1, ng = 0;
    // ng の範囲をもっと厳しく
    rep(i, 1, n){
        chmax(ng, (ld)(h[i-1]-h[i])/(x[i]-x[i-1])*x[i-1]+h[i-1]);
    }
    // ng の範囲をもっと厳しく
    rep(i, 1, n){
        chmax(ng, (ld)(h[i-1]-h[i])/(x[i]-x[i-1])*x[i-1]+h[i-1]);
    }
    cout << setprecision(20) << ng << endl;


    return 0;
}