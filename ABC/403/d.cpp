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
    int n, d; cin >> n >> d;
    vector<int> a(n);
    vector<int> cnt(1000005);
    rep(i, 0, n) cin >> a[i], cnt[a[i]]++;

    if(d == 0){
        int ans = 0;
        rep(i, 0, 1000005){
            ans += max(0, cnt[i]-1);
        }
        cout << ans << endl;
    }else{
        int ans = 0;
        rep(i, 0, d){
            vector<int> dp(2);
            for(int j = i; j <= 1000000; j += d){
                vector<int> ndp(2);
                ndp[0] = min(dp[0], dp[1])+cnt[j];
                ndp[1] = dp[0];
                swap(dp, ndp);
            }
            ans += min(dp[0], dp[1]);
        }
        cout << ans << endl;
    }
    

    return 0;
}