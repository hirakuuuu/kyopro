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
    int n, m, l; cin >> n >> m >> l;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<vector<ll>> cost(l, vector<ll>(m));
    rep(i, 0, l){
        for(int j = i; j < n; j += l){
            rep(k, 0, m){
                cost[i][k] += (k-a[j]+m)%m;
            }
        }
    }

    vector<ll> dp(m, INF);
    dp[0] = 0;
    rep(i, 0, l){
        vector<ll> ndp(m, INF);
        rep(j, 0, m){
            rep(k, 0, m){
                chmin(ndp[(j+k)%m], dp[j]+cost[i][k]);
            }
        }
        swap(dp, ndp);
        // rep(j, 0, m){
        //     cout << dp[j] << ' ';
        // }
        // cout << endl;
    }
    cout << dp[0] << endl;
    
    return 0;
}