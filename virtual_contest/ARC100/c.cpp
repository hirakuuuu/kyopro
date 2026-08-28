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
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i]; 
        a[i] -= i+1;
    }
    sort(a.begin(), a.end());

    ll sum_l = 0, sum_r = 0;
    rep(i, 0, n) sum_r += a[i];
    ll ans = INF;
    rep(i, 0, n){
        chmin(ans, (a[i]*i-sum_l)+(sum_r-a[i]*(n-i)));
        sum_l += a[i];
        sum_r -= a[i];
    }
    cout << ans << endl;
    return 0;
}