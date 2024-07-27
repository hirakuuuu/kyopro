#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
ACLの畳み込みは任意の MOD でできるわけではない
今回は畳み込みを使わなくても愚直に O(n^2) で計算すれば十分である
*/

int main(){
    int n, c; cin >> n >> c;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<vector<mint>> ab(n, vector<mint>(c+1));
    rep(i, 0, n){
        rep(x, a[i], b[i]+1){
            mint mx = mint(x);
            rep(j, 0, c+1){
                ab[i][j] += mx.pow(j);
            }
        }
    }



    vector<mint> dp = ab[0];
    rep(i, 1, n){
        vector<mint> dp_(c+1);
        rep(j, 0, c+1){
            rep(k, 0, c-j+1){
                dp_[j+k] += dp[j]*ab[i][k];
            }
        }
        swap(dp, dp_);
    }
    cout << dp[c].val() << endl;
    
    return 0;
}