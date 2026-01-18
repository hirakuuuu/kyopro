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


int main(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> ab(n);
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        ab[i] = {a, b};
    }
    sort(ab.begin(), ab.end(), [&](auto c, auto d){
        return (c.first-1)*d.second < (d.first-1)*c.second;
    });

    vector<ll> dp(k+1, 1);
    rep(i, 0, n){
        vector<ll> ndp = dp;
        rep(j, 0, k){
            chmax(ndp[j+1], dp[j]*ab[i].first+ab[i].second);
        }
        swap(dp, ndp);
    }
    cout << dp[k] << endl;



    
    return 0;
}