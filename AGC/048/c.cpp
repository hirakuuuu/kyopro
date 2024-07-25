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
間に着目すると、１回の操作はその間のマスを隣接項のどちらかに足すことと同じ
結局、間の数ごとに区間を選んで当てはめてあげればよい
そうすると操作回数の最小値も簡単に計算できる max(i-l, 0)+max(r-1-i, 0) になる
*/

int main(){
    ll n, L; cin >> n >> L;
    vector<ll> a(n+2), b(n+2);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> b[i];
    a[n+1] = b[n+1] = L+1;
    
    vector<ll> x(n+1), y(n+1);
    rep(i, 0, n+1) x[i] = a[i+1]-a[i]-1;
    rep(i, 0, n+1) y[i] = b[i+1]-b[i]-1;
    // rep(i, 0, n+1){
    //     cout << x[i] << ' ';
    // }
    // cout << endl;
    // rep(i, 0, n+1){
    //     cout << y[i] << ' ';
    // }
    // cout << endl;

    // x を y にするのは, 隣接したいくつかの項をまとめて y にするのと同じ
    ll ans = 0;
    ll l = 0, r = 0, d = 0;
    rep(i, 0, n+1){
        d = 0;
        if(y[i] == 0) continue;
        while(l < n+1 && x[l] == 0) l++;
        r = l;
        while(r < n+1 && d < y[i]){
            d += x[r];
            r++;
        }
        if(d != y[i]){
            cout << -1 << endl;
            return 0;
        }
        // if(d == 0) continue;
        ans += max(r-1, (ll)i)-min(l, (ll)i);
        l = r;
    }

    cout << ans << endl;

    
    return 0;
}