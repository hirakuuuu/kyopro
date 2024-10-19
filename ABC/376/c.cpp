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
    vector<ll> a(n), c(n-1), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1) cin >> c[i];
    rep(i, 0, n-1) b[i] = c[i];
    b[n-1] = IINF;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // そもそも可能かどうか
    rep(i, 0, n){
        if(a[i] > b[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    ll ng = 0, ok = IINF;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        vector<ll> d = c;
        d.push_back(mid);
        sort(d.begin(), d.end());
        bool f = true;
        rep(i, 0, n){
            if(a[i] > d[i]){
                f = false;
                break;
            }
        }
        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}