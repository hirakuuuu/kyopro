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
    int T; cin >> T;
    while(T--){
        int n, h; cin >> n >> h;
        int mx = h, mi = h;
        int pre = 0;
        bool ok = true;
        rep(i, 0, n){
            int t, l, u; cin >> t >> l >> u;
            int d = t-pre;
            int nu = mx+d, nl = max(1, mi-d);
            if(nu < l || u < nl){
                ok = false;
            }else{
                mx = min(u, nu);
                mi = max(l, nl);
            }
            pre = t;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}