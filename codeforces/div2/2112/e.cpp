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

    vector<int> dp(500005, IINF);
    dp[1] = 1;
    rep(i, 3, 500005){
        if(i%2 == 0) continue;
        chmin(dp[i], dp[i-2]+1);
        for(int y = 3; y*y <= i; y+=2){
            if(i%y == 0){
                chmin(dp[i], dp[i/y]+dp[y]-1);
            }
        }
    }
    int t; cin >>t;
    while(t--){
        int m; cin >> m;
        if(m%2 == 0){
            cout << -1 << endl;
            continue;
        }
        cout << dp[m] << endl;




    }
    
    return 0;
}