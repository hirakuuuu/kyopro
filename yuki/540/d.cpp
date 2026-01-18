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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    rep(i, 0, k){
        int A; cin >> A; A--;
        a[A] = 1;
    }
    vector<vector<int>> t(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n){
        cin >> t[i][j];
    }

    vector<vector<int>> dp(1<<n, vector<int>(n, IINF));
    rep(i, 0, n) dp[1<<i][i] = 0;
    rep(i, 0, 1<<n){
        rep(j, 0, n){
            if((i>>j)&1){
                rep(l, 0, n){
                    if(!((i>>l)&1)){
                        chmin(dp[i+(1<<l)][l], dp[i][j]+t[j][l]);
                    }
                }
            }
        }
    }


    int ans = IINF;
    rep(i, 0, 1<<n){
        int tmp = i;
        int pc = 0;
        rep(j, 0, n){
            if(tmp>>j&1) pc++;
        }
        if(pc >= m){
            rep(j, 0, n){
                if(a[j]) chmin(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;


    return 0;
}