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


/*
ダブリングで 2^k 回の操作で到達できる位置を持っておく
これで n回の操作で到達できる位置が O(log n) で求まる
後は二分探索
*/


int main(){
    int n; cin >> n;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];
    ll L; cin >> L;
    vector<vector<int>> dp(30, vector<int>(n));
    rep(i, 0, n){
        int r = upper_bound(x.begin(), x.end(), x[i]+L)-x.begin();
        r--;
        dp[0][i] = r;
    }
    rep(i, 1, 30){
        rep(j, 0, n){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    
    reverse(x.begin(), x.end());
    rep(i, 0, n) x[i] = -x[i];
    vector<vector<int>> rev(30, vector<int>(n));
    rep(i, 0, n){
        int r = upper_bound(x.begin(), x.end(), x[i]+L)-x.begin();
        r--;
        rev[0][n-1-i] = n-1-r;
    }
    rep(i, 1, 30){
        rep(j, 0, n){
            rev[i][j] = rev[i-1][rev[i-1][j]];
        }
    }

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
        int ok = IINF, ng = 0;
        if(a < b){
            while(ok-ng > 1){
                int mid = (ok+ng)/2;
                int pos = a;
                rep(i, 0, 30){
                    if((mid>>i)&1){
                        pos = dp[i][pos];
                    }
                }
                if(b <= pos) ok = mid;
                else ng = mid;
            }
        }else{
            while(ok-ng > 1){
                int mid = (ok+ng)/2;
                int pos = a;
                rep(i, 0, 30){
                    if((mid>>i)&1){
                        pos = rev[i][pos];
                    }
                }
                if(pos <= b) ok = mid;
                else ng = mid;
            }
        }
        cout << ok << endl;
    }

    return 0;
}