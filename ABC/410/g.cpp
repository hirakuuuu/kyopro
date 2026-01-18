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
    vector<pair<int, int>> ba(n);
    vector<pair<int, int>> ab(n);
    rep(i, 0, n){
        int a, b; cin >> a >> b; a--, b--;
        if(a > b) swap(a, b);
        ab[i] = {a, b};
        ba[i] = {b, a};
    }

    int ans = 0;
    vector<int> mx_l(2*n+1); // mx[i]: l <= i を満たす区間のみを使ったときの最大値
    {
        // a の降順でソートして，b の最長増加部分列を求める
        vector<int> dp(n+1, IINF);
        sort(ab.rbegin(), ab.rend());
        rep(i, 0, n){
            auto [a, b] = ab[i];
            int pos = lower_bound(dp.begin(), dp.end(), b)-dp.begin();
            chmax(ans, pos+1);
            dp[pos] = b;
            mx_l[a] = pos+1;
            // cout << b << ' ' << pos+1 << endl;
        }
        rrep(i, 2*n-1, 0){
            chmax(mx_l[i], mx_l[i+1]);
            // cout << i << ' ' << mx_l[i] << endl;
        }
    }
    vector<int> mx_r(2*n+1); // mx[i]: i <= rを満たす区間のみを使ったときの最大値
    {
        // b の昇順でソートして，a の最長減少部分列を求める
        vector<int> dp(n+1, IINF);
        sort(ba.begin(), ba.end());
        rep(i, 0, n){
            auto [b, a] = ba[i];
            int pos = lower_bound(dp.begin(), dp.end(), -a)-dp.begin();
            chmax(ans, pos+1);
            dp[pos] = -a;
            mx_r[b] = pos+1;

        }
        rep(i, 1, 2*n+1){
            chmax(mx_r[i], mx_r[i-1]);
        }
    }

    // どこかで切れる場合を考える
    rep(i, 0, 2*n){
        // cout << mx_r[i] << ' ' << mx_l[i+1] << endl;
        chmax(ans, mx_r[i]+mx_l[i+1]);
    }
    cout << ans << endl;

    return 0;
}