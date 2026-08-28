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
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll sum_a = 0;
    rep(i, 0, k) sum_a += a[i];
    if(sum_a < x){
        cout << -1 << endl;
        return 0;
    }
    int ans = n;
    rep(i, 0, k-1){
        sum_a -= a[i];
        if(sum_a < x){
            cout << ans << endl;
            return 0;
        }
        ans--;
    }
    cout << ans << endl;
    return 0;
}