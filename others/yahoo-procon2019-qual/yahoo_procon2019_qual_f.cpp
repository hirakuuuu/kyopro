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

int main(){
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> r(n), b(n);
    int R = 0;
    rep(i, 0, n){
        if(s[i] == '0'){ r[i] += 2; }
        if(s[i] == '1'){ r[i]++; b[i]++; }
        if(s[i] == '2'){ b[i] += 2; }
        R += r[i];
    }

    vector<mint> dp(R+1);
    dp[0] = 1;
    int cr = r[0], cb = b[0];
    rep(i, 1, 2*n+1){
        vector<mint> dp_(R+1);
        rep(j, 0, min(i, R)+1){
            // b が使える場合
            if(cb-(i-1-j) >= 1) dp_[j] += dp[j]; 
            if(j >= 1 && cr-(j-1) >= 1) dp_[j] += dp[j-1]; 
        }
        swap(dp, dp_);
        if(i < n){
            cr += r[i];
            cb += b[i];
        }
    }
    cout << dp[R].val() << endl;
    
    return 0;
}