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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    // dp[i][j] := 上 10 桁が i に一致し，下 10 桁が j の部分集合となる要素の総積
    vector<vector<mint>> dp(1<<10, vector<mint>(1<<10, 1));
    rep(i, 0, n){
        int l = a[i]>>10;
        int mask = (1<<10)-1;
        rep(j, 0, 1<<10){
            if(((a[i]&mask)|j) == j) dp[l][j] *= a[i];
        }

        mint ans = 1;
        rep(j, 0, 1<<10){
            if((l|j) == l){
                ans *= dp[j][(a[i]&mask)];
            }
        }
        cout << ans.val() << endl;
    }

    return 0;
}