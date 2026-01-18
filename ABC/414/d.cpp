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
    vector<ll> x(n);
    rep(i, 0, n){
        cin >> x[i];
    }

    sort(x.begin(), x.end());
    ll len = x[n-1]-x[0];
    vector<ll> y(n-1);
    rep(i, 0, n-1){
        y[i] = x[i+1]-x[i];
    }

    sort(y.rbegin(), y.rend());
    rep(i, 0, m-1) len -= y[i];
    cout << len << endl;


    
    return 0;
}