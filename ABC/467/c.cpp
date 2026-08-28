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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n), b(n-1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1) cin >> b[i];
    
    vector<int> dp(2, IINF);
    dp[a[0]] = 0;
    dp[1-a[0]] = 1;
    rep(i, 0, n-1){
        vector<int> ndp(2, IINF);
        if(b[i] == 0){
            if(a[i+1] == 0){
                chmin(ndp[0], dp[0]);
                chmin(ndp[1], dp[1]+1);
            }else{
                chmin(ndp[1], dp[1]);
                chmin(ndp[0], dp[0]+1);
            }
        }else{
            if(a[i+1] == 0){
                chmin(ndp[1], dp[0]+1);
                chmin(ndp[0], dp[1]);
            }else{
                chmin(ndp[1], dp[0]);
                chmin(ndp[0], dp[1]+1);
            }
        }
        swap(dp, ndp);
    }
    cout << min(dp[0], dp[1]) << endl;
    return 0;
}