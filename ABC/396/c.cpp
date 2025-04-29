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
    int n, m; cin >> n >> m;
    vector<int> b(n), w(m);
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, m) cin >> w[i];
    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());
    ll ans = 0, sum_w = 0, sum_b = 0, p_b = 0;
    rep(i, 0, n){
        if(b[i] > 0) p_b += b[i];
    }
    rep(i, 0, m+1){
        if(n < i) break;
        // 白のボールを i 個選ぶとき，b は大きい順に i 個選ぶかつ，正の値があればそれも選ぶ.
        chmax(ans, sum_w+sum_b+p_b);
        if(i < m) sum_w += w[i];
        if(i < n){
            sum_b += b[i];
            if(b[i] > 0) p_b -= b[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}