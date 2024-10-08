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

int main(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll ans = n, sum = 0;
    rep(i, 0, n){
        sum += a[i];
        if(sum > x){
            chmin(ans, i+1);
            break;
        }
    }
    sum = 0;
    rep(i, 0, n){
        sum += b[i];
        if(sum > y){
            chmin(ans, i+1);
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}