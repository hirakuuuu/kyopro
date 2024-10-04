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
    ll k; cin >> k;
    vector<int> x(n), a(n);
    rep(i, 0, n){ cin >> x[i]; x[i]--; }
    rep(i, 0, n) cin >> a[i];

    vector<vector<int>> f(61, vector<int>(n));
    rep(i, 0, n){
        f[0][i] = x[i];
    }
    rep(j, 1, 61){
        rep(i, 0, n){
            f[j][i] = f[j-1][f[j-1][i]];
        }
    }
    
    vector<int> ans(n);
    rep(i, 0, n){
        int cur = i;
        rep(j, 0, 61){
            if((k>>j)&1) cur = f[j][cur];
        }
        ans[i] = a[cur];
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}