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
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

constexpr int F = 900000;

int main(){
    ios::sync_with_stdio(false);  // 高速入出力
    cin.tie(nullptr);
    int n, f; cin >> n >> f;
    vector<int> a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) cin >> c[i];


    bitset<F+1> d;
    d[a[0]] = d[b[0]] = d[c[0]] = 1;
    cout << d.count() << '\n';

    rep(i, 1, n){
        int x[3] = {a[i], b[i], c[i]};
        sort(x, x+3);  // シフト量の小さい順に処理
        bitset<F+1> e;
        e |= d<<x[0];
        e |= d<<x[1];
        e |= d<<x[2];
        cout << e.count() << '\n';
        d = move(e);
    }

    return 0;
}