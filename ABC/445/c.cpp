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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i], a[i]--;
    vector<int> dp(n);
    rep(i, 0, n){
        int pos = i;
        rep(j, 0, 10){
            pos = a[pos];
        }
        dp[i] = pos;
    }

    rep(i, 0, 99){
        vector<int> ndp(n);
        rep(j, 0, n){
            ndp[j] = dp[dp[j]];
        }
        swap(dp, ndp);
    }
    rep(i, 0, n){
        cout << dp[i]+1 << ' ';
    }
    cout << endl;
    
    return 0;
}