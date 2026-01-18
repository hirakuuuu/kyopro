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
    ll n, l; cin >> n >> l;
    vector<ll> r(n), c(n);
    rep(i, 0, n){
        cin >> r[i] >> c[i]; r[i]--;
    }
    if(n%2 == 1){
        cout << "no" << endl;
        return 0;
    }
    {
        vector<ll> c_ = c;
        sort(c_.begin(), c_.end());
        c_.erase(unique(c_.begin(), c_.end()), c_.end());
        ll pre = -1;
        map<ll, ll> comp;
        for(auto cc: c_){
            if(pre == -1){
                comp[cc] = 2-cc%2;
                pre = comp[cc];
            }else{
                if((cc-pre)%2 == 0) comp[cc] = pre+2;
                else comp[cc] = pre+1;
                pre = comp[cc];
            }
        }
        if((l-pre)%2 == 0) l = pre;
        else l = pre+1;
        rep(i, 0, n){
            c[i] = comp[c[i]];
        }
    }
    
    /*
        0: .
           .
        
        1: .
           #
        
        2: #
           .
        
        3: #
           #
    */
    vector<int> blocks(l+1);
    rep(i, 0, n) blocks[c[i]] += 1<<(1-r[i]);
    vector<vector<int>> dp(l+1, vector<int>(4, IINF));
    dp[0][3] = 0;
    rep(i, 1, l+1){
        if(blocks[i] == 0){
            chmin(dp[i][1], dp[i-1][2]);
            chmin(dp[i][2], dp[i-1][1]);
            chmin(dp[i][3], dp[i-1][3]);
        }else if(blocks[i] == 1){
            chmin(dp[i][3], dp[i-1][1]);
            chmin(dp[i][3], dp[i-1][2]+1);
            chmin(dp[i][1], dp[i-1][3]);
        }else if(blocks[i] == 2){
            chmin(dp[i][3], dp[i-1][1]+1);
            chmin(dp[i][3], dp[i-1][2]);
            chmin(dp[i][2], dp[i-1][3]);
        }else{
            chmin(dp[i][1], dp[i-1][1]+1);
            chmin(dp[i][2], dp[i-1][2]+1);
            chmin(dp[i][3], dp[i-1][3]);
        }
    }

    cout << dp[l][3] << endl;

    return 0;
}