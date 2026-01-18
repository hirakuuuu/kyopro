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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> dp(1<<n);
        dp[0] = 1;
        rep(i, 1, 1<<n){
            if(s[i-1] == '1') continue;
            rep(j, 0, n){
                if((i>>j)&1){
                    dp[i] |= dp[i-(1<<j)];
                }
            }
        }
        if(dp.back()) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
    return 0;
}