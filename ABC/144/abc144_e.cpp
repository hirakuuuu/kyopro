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
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
a[i]*b[i]の最大値が最小になる割り当て→a を昇順、bを降順
最大値の最小値→二分探索
*/

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    ll ok = 9e18, ng = -1;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2, cnt = 0;
        rep(i, 0, n){
            cnt += max(0LL, (a[i]*f[i]-mid+f[i]-1)/f[i]);
        }
        if(cnt <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}