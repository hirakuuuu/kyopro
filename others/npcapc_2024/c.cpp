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
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n), d(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) cin >> d[i];

    vector<ll> acc_c(n+1), acc_d(n+1);
    rep(i, 0, n) acc_c[i+1] = acc_c[i]+c[i];
    rep(i, 0, n) acc_d[i+1] = acc_d[i]+d[i];

    ll sum = 0;
    rep(i, 0, n) sum += a[i];
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, 0, n) que.push(b[i]-a[i]);
    ll ans = sum+acc_c[n];
    rep(i, 0, n){
        sum += que.top(); que.pop();
        chmin(ans, sum+acc_c[n-1-i]+acc_d[i+1]);
    }
    cout << ans << endl;
    
    return 0;
}