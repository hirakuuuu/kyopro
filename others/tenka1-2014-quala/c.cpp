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
    int n, m; cin >> n >> m;
    vector<string> p(n);
    rep(i, 0, n) cin >> p[i];

    vector<vector<int>> able(n, vector<int>(n));
    rep(i, 0, n) able[i][i] = 1;
    rep(i, 0, n){
        rep(j, i+1, n){
            bool ok = true;
            rep(k, 0, m){
                if((p[i][k] != '*') && (p[j][k] != '*') && (p[i][k] != p[j][k])){
                    ok = false;
                    break;
                }
            }
            if(ok) able[i][j] = able[j][i] = 1;
        }
    }

    vector<int> dp((1<<n), IINF);
    dp[0] = 0;
    rep(i, 1, 1<<n){
        dp[i] = __popcount(i);
        bool f = true;
        rep(j, 0, n){
            if(!((i>>j)&1)) continue;
            rep(k, j+1, n){
                if(!((i>>k)&1)) continue;
                if(!able[j][k]) f = false;
            }
        }
        if(f) chmin(dp[i], 1);
    }
    rep(i, 0, 1<<n){
        for(int s = i; ; s = (s-1)&i){
            if(s == 0) break;
            chmin(dp[i], dp[s]+dp[i-s]); // 差集合は s-i で取れる
        }
    }
    cout << dp[(1<<n)-1] << endl;

    
    return 0;
}