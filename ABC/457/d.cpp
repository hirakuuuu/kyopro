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
    ll k; cin >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ng = 3e18, ok = 0;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        rep(i, 0, n){
            cnt += max(0LL, (mid-a[i]+i)/(i+1));
            if(cnt > k) break;
        }
        if(cnt <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}