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
    vector<int> r(n), c(n);
    int mi_r = IINF, mx_r = -IINF;
    int mi_c = IINF, mx_c = -IINF;
    rep(i, 0, n){
        cin >> r[i] >> c[i];
        chmin(mi_r, r[i]);
        chmin(mi_c, c[i]);
        chmax(mx_r, r[i]);
        chmax(mx_c, c[i]);
    }

    int ans = max(mx_r-mi_r, mx_c-mi_c);
    if(ans%2 == 0) ans /= 2;
    else ans = (ans+1)/2;
    cout << ans << endl;
    return 0;
}