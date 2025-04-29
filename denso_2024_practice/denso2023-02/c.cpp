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
    vector<double> p(n);
    rep(i, 0, n) cin >> p[i], p[i] /= 100.0;

    double prob = 1.0;
    vector<double> ans(n);
    rep(i, 0, n){
        ans[i] = prob*p[i];
        prob *= (1.0-p[i]);
    }
    rep(i, 0, n){
        cout << setprecision(20) << ans[i]/(1.0-prob) << endl;
    }
    
    return 0;
}