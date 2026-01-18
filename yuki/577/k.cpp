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

int mod = 998244353;

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    unordered_map<ll, int> dp;
    auto id = [&](int u, int l, int d, int r) -> ll {
        ll res = 0;
        res += (ll)u<<30;
        res += (ll)l<<20;
        res += (ll)d<<10;
        res += (ll)r;
        return res;
    };
    rep(i, 0, n){
        dp[id(i, n-1-i, i, n-1-i)] = 1;
    }

    rep(d, 1, n){
        rep(i, 0, n){
            int j = n-1-d-i;
            if(!inr(0, j, n)) continue;
            rep(k, 0, n){
                int l = n-1+d-k;
                if(!inr(0, l, n)) continue;

                if(s[i][j] != s[k][l]) continue;

                ll i1 = id(i, j, k, l);
                if(inr(0, i+1, n) && inr(0, k-1, n)) dp[i1] = (dp[i1]+dp[id(i+1, j, k-1, l)])%mod;
                if(inr(0, i+1, n) && inr(0, l-1, n)) dp[i1] = (dp[i1]+dp[id(i+1, j, k, l-1)])%mod;
                if(inr(0, j+1, n) && inr(0, k-1, n)) dp[i1] = (dp[i1]+dp[id(i, j+1, k-1, l)])%mod;
                if(inr(0, j+1, n) && inr(0, l-1, n)) dp[i1] = (dp[i1]+dp[id(i, j+1, k, l-1)])%mod;
            }
        }
    }
    cout << dp[id(0, 0, n-1, n-1)] << endl;
    
    
    return 0;
}