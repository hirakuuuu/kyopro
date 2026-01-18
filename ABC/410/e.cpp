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
    int h, m; cin >> h >> m;

    vector<int> dp(h+1);
    dp[h] = m;
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        vector<int> ndp(h+1, -1);
        rep(j, 0, h+1){
            if(dp[j] == -1) continue;
            if(j >= a) chmax(ndp[j-a], dp[j]);
            if(dp[j] >= b) chmax(ndp[j], dp[j]-b); 
        }
        swap(dp, ndp);
        bool ok = false;
        rep(j, 0, h+1){
            if(dp[j] != -1) ok = true;
        }
        if(!ok){
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
    
    return 0;
}