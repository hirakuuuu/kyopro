#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
using mint = modint;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}




int main(){
    int t, m; cin >> t >> m;
    mint::set_mod(m);
    vector<vector<mint>> co(5005, vector<mint>(5005));
    co[0][0] = 1;
    rep(i, 1, 5005){
        co[i][0] = 1;
        rep(j, 1, 5005){
            co[i][j] = co[i-1][j]+co[i-1][j-1];
        }
    }

    while(t--){
        int n; cin >> n;
        vector<int> c(n);
        int tot = 0;
        rep(i, 0, n){
            cin >> c[i];
            tot += c[i];
        }

        mint ans = 1;
        rep(i, 0, n){
            ans *= co[tot][c[i]];
            tot -= c[i];
        }
        cout << ans.val() << endl;
    }
    return 0;
}