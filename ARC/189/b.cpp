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
    vector<ll> X(n);
    rep(i, 0, n) cin >> X[i];

    vector<vector<ll>> d(2);
    rep(i, 1, n){
        d[(i&1)].push_back(X[i]-X[i-1]);
    }
    rep(i, 0, 2) sort(d[i].begin(), d[i].end());

    ll ans = X[0], tmp = X[0];
    vector<int> l(2);
    rep(i, 1, n){
        tmp += d[(i&1)][l[(i&1)]];
        ans += tmp;
        l[(i&1)]++;
    }
    cout << ans << endl;


    
    return 0;
}