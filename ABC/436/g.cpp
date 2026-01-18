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
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    ll m; cin >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<mint> dp(20001);
    dp[0] = 1;
    while(m){
        rep(i, 0, n){
            rrep(j, 20000, a[i]){
                dp[j] += dp[j-a[i]];
            }
        }
        vector<mint> old(20001);
        swap(dp, old);
        rep(j, 0, 20001){
            int nj = j;
            if((nj&1) != (m&1)) nj++;
            dp[nj/2] += old[j];
        }
        m >>= 1;
    }

    cout << dp[0].val() << endl; // 繰り上がりがないのがちょうど
    return 0;
}