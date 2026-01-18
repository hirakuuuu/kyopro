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
    int n, l; cin >> n >> l;
    vector<int> p(n);
    vector<ll> c(l);
    p[0] = 0;
    c[0]++;
    rep(i, 1, n){
        int d; cin >> d;
        p[i] = (p[i-1]+d)%l;
        c[p[i]]++;
    }
    if(l%3 != 0){
        cout << 0 << endl;
        return 0;
    }
    
    int e = l/3;
    ll ans = 0;
    rep(i, 0, l){
        ans += c[i]*c[(i+e)%l]*c[(i+2*e)%l];
    }
    cout << ans/3 << endl;


    return 0;
}