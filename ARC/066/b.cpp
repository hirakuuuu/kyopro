#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- 桁 DP だけどある程度状態をまとめないとだめ
- N と N 未満で分けるとうまくいかない
- N と N-1 と N-2 以下で分けるとうまく遷移が書ける
*/

int main(){
    ll n; cin >> n;

    mint dp[3];
    dp[0] = 1;
    rrep(i, 61, 0){
        mint ndp[3];
        int f = (n>>i)&1;

        if(f){
            // 0
            ndp[0] += dp[0];
            ndp[1] += dp[0];

            // 1
            ndp[1] += dp[1];
            ndp[2] += dp[1]*2;

            // 2
            ndp[2] += dp[2]*3;
        }else{
            // 0
            ndp[0] += dp[0];

            // 1
            ndp[0] += dp[1];
            ndp[1] += dp[1];
            ndp[2] += dp[1];

            // 2
            ndp[2] += dp[2]*3;
        }

        swap(dp, ndp);
    }

    cout << (dp[0]+dp[1]+dp[2]).val() << endl;

    
    return 0;
}