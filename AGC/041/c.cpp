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
    // 4, 6 の足し算で作れるやつは全部行ける
    vector<int> p = {4, 5, 6, 7}, zero = {0, 0, 0, 0};
    vector<vector<int>> dp(1001, zero);
    dp[4] = {1, 0, 0, 0};
    dp[5] = {0, 1, 0, 0};
    dp[6] = {0, 0, 1, 0};
    dp[7] = {0, 0, 0, 1};
    rep(i, 8, 1001){
        rep(j, 0, 3){
            if(dp[i-p[j]] != zero){
                dp[i] = dp[i-p[j]];
                dp[i][j]++;
            }
        }
    }
    int n; cin >> n;
    vector<vector<char>> ans(n, vector<char>(n, '.'));
    if(n%3 == 0){
        /*
            #..
            #..
            .##
            の繰り返しで行ける
        */
        rep(i, 0, n/3){
            ans[3*i][3*i] = ans[3*i+1][3*i] = 'a';
            ans[3*i+2][3*i+1] = ans[3*i+2][3*i+2] = 'a';
        }
    }else if(dp[n] != zero){
        // 4, 5, 6, 7の繰り返し
        vector<vector<string>> f = {
            {
                "abcc",
                "abdd",
                "ccab",
                "ddab",
            },
            {
                "a.bbc",
                "add.c",
                "cc.bd",
                "..abd",
                "ddaee",
            },
            {
                "aabbcc",
                "bcczz.",
                "ba.d..",
                ".a.daa",
                "c.a..b",
                "c.a..b"
            },
            {
                "aabbcc.",
                "bccdd..",
                "b...aab",
                ".a.a..b",
                ".a.a..c",
                "a.a...c",
                "a.a..dd",
            },
        };
        int off = 0;
        rep(l, 0, p.size()){
            rep(i, 0, dp[n][l]){
                rep(j, 0, p[l]){
                    rep(k, 0, p[l]){
                        ans[off+j][off+k] = f[l][j][k];
                    }
                }
                off += p[l];
            }
        }
    }else{
        cout << -1 << endl;
        return 0;
    }
    rep(i, 0, n){
        rep(j, 0, n){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}