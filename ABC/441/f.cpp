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
    int n, m; cin >> n >> m;
    vector<ll> p(n+1), v(n+1);
    rep(i, 1, n+1) cin >> p[i] >> v[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    rep(i, 1, n+1){
        rep(j, 0, m+1){
            chmax(dp[i][j], dp[i-1][j]);
            if(j-p[i] >= 0) chmax(dp[i][j], dp[i-1][j-p[i]]+v[i]);
        }
    }

    // rep(i, 0, n+1){
    //     rep(j, 0, m+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    ll mx = dp[n][m];
    vector<int> a1(n+1), a2(n+1);
    vector<int> b1(n+1), b2(n+1);
    vector<int> cnt(n+1);
    vector<int> ids;
    rrep(i, m, 1){
        if(dp[n][i] != mx) break;
        ids.push_back(i);
    }
    rrep(i, n, 1){

        vector<int> nids;
        for(auto w: ids){
            if(dp[i-1][w] == dp[i][w]){
                a1[i] = 1;
                nids.push_back(w);
            }else{
                b1[i] = 1;
            }
            if(w >= p[i] && dp[i-1][w-p[i]]+v[i] == dp[i][w]){
                a2[i] = 1;
                nids.push_back(w-p[i]);
            }else{
                b2[i] = 1;
            }
        }
        sort(nids.begin(), nids.end());
        nids.erase(unique(nids.begin(), nids.end()), nids.end());
        swap(ids, nids);
    }

    rep(i, 1, n+1){
        // cout << a1[i] << ' ' << a2[i] << ' ' << b1[i] << ' ' << b2[i] << endl;
        if(!a1[i] && !b2[i]) cout << 'A';
        else if(!a2[i] && !b1[i]) cout << 'C';
        else cout << 'B';
    }
    cout << endl;
    
    return 0;
}