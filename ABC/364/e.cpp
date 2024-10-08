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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    vector<vector<int>> dp_a(n+1, vector<int>(x+1, IINF));
    dp_a[0][0] = 0;
    rep(i, 0, n){
        vector<vector<int>> dp_a_ = dp_a;
        rep(k, 1, n+1){
            rep(j, 0, x+1){
                if(j-a[i] >= 0) chmin(dp_a[k][j], dp_a_[k-1][j-a[i]]+b[i]);
                chmin(dp_a[k][j], dp_a_[k][j]);
            }
        }
    }

    vector<vector<int>> dp_b(n+1, vector<int>(y+1, IINF));
    dp_b[0][0] = 0;
    rep(i, 0, n){
        vector<vector<int>> dp_b_ = dp_b;
        rep(k, 1, n+1){
            rep(j, 0, y+1){
                if(j-b[i] >= 0) chmin(dp_b[k][j], dp_b_[k-1][j-b[i]]+a[i]);
                chmin(dp_b[k][j], dp_b_[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, 0, n+1){
        rep(j, 0, x+1){
            if(dp_a[i][j] <= y) chmax(ans, i);
        }
    }
    rep(i, 0, n+1){
        rep(j, 0, y+1){
            if(dp_b[i][j] <= x) chmax(ans, i);
        }
    }
    if(ans < n) ans++;
    cout << ans << endl;
    return 0;
}