#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc236/tasks/abc236_e

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<double> dp(n+1), dp_(n+1);
    double l = 1.0, r = 1e9+1;
    while(r-l > 1e-6){
        double mid = (r+l)/2.0;
        rep(i, 0, n){
            dp[i+1] = max(dp[i], dp_[i])+(double)a[i]-mid;
            dp_[i+1] = dp[i];
        }

        if(max(dp[n], dp_[n]) >= 0.0) l = mid;
        else r = mid;
    }

    printf("%.10f\n", l);

    int L = 1, R = 1e9+1;
    while(R-L > 1){
        int mid = (R+L)/2;
        rep(i, 0, n){
            if(a[i] >= mid) dp[i+1] = max(dp[i], dp_[i])+1;
            else dp[i+1] = max(dp[i], dp_[i])-1;
            dp_[i+1] = dp[i];
        }

        if(max(dp[n], dp_[n]) > 0) L = mid;
        else R = mid;
    }

    cout << L << endl;
    
    return 0;
}