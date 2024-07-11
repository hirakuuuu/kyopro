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
前から順番に選んだ個数を持つようにすると、100 個目を見たときに 0 個の状態とか持つ必要がない
よって, 持つべき個数の種類が十分少ないことが予想できる
実際計算すると, ３通り程度しかないので、map 等を使っても十分高速
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<map<int, ll>> dp(n+1);
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = -INF;
    dp[1][0] = 0;
    dp[1][1] = a[0];
    dp[1][2] = -INF;
    rep(i, 1, n){
        int tmp = n/2-(n-i)/2;
        while(tmp <= (i+2)/2){
            dp[i+1][tmp] = -INF;
            if(dp[i].find(tmp) != dp[i].end()) chmax(dp[i+1][tmp], dp[i][tmp]);
            if(dp[i-1].find(tmp-1) != dp[i-1].end()) chmax(dp[i+1][tmp], dp[i-1][tmp-1]+a[i]);
            tmp++;
        }
    }
    cout << dp[n][n/2] << endl;
    return 0;
}