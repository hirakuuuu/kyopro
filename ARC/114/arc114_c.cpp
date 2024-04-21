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

/*
総和とかを考える問題は、細かい部分に着目し、その部分が全体にどれくらい寄与するかを考える
maspyさんの極大長方形の寄与を考える解説と同じ解法だった
https://maspypy.com/atcoder-sequence-scores-arc-114-c

*/

int main(){
    int n, m; cin >> n >> m;
    mint ans = 0;
    vector<vector<mint>> p(m+1, vector<mint>(n+1));
    rep(i, 1, m+1){
        p[i][0] = 1;
        rep(j, 1, n+1){
            p[i][j] = p[i][j-1]*i;
        }
    }
    // [i以上の数], i未満の数, ...
    rep(i, 1, m+1){
        rep(r, 1, n+1){
            if(r == n) ans += p[m-i+1][r]-p[m-i][r];
            else ans += (p[m-i+1][r]-p[m-i][r])*(i-1)*(p[m][n-r-1]);
        }
    }
    // ..., i未満の数, [i以上の数]
    rep(i, 1, m+1){
        rep(l, 2, n+1){
            ans += (p[m-i+1][n-l+1]-p[m-i][n-l+1])*(i-1)*p[m][l-2];
        }
    }
    // ..., i未満の数, [i以上の数], i未満の数, ...
    rep(i, 1, m+1){
        mint ii = (i-1)*(i-1);
        rep(r, 1, n-1){
            mint cnt = n-2-r+1;
            ans += cnt*(p[m-i+1][r]-p[m-i][r])*ii*(p[m][n-r-2]);
        }
    }
    cout << ans.val() << endl;
    return 0;
}