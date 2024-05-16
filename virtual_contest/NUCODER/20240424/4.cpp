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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    reverse(a.begin(), a.end());
    vector<int> dp(n+1, IINF);
    rep(i, 0, n){
        auto pos = upper_bound(dp.begin(), dp.end(), a[i])-dp.begin();
        dp[pos] = a[i];
    }
    int ans = 0;
    rep(i, 0, n+1){
        if(dp[i] == IINF) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}