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
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    string sss = s+s+s;
    vector<int> pos;
    rep(i, 0, 3*n){
        if(sss[i] == 'x') pos.push_back(i);
    }

    vector<vector<pair<ll, ll>>> dp(50, vector<pair<ll, ll>>(n));
    rep(i, 0, n){
        auto itr = lower_bound(pos.begin(), pos.end(), i);
        itr++;
        dp[0][i] = {(*itr)/n, (*itr)%n};
    }

    rep(j, 1, 50){
        rep(i, 0, n){
            dp[j][i].first = dp[j-1][i].first+dp[j-1][dp[j-1][i].second].first;
            dp[j][i].second = dp[j-1][dp[j-1][i].second].second;
        }
    }

    vector<pair<ll, ll>> to(n);
    rep(i, 0, n){
        to[i].second = i;
    }
    rep(j, 0, 50){
        if((k>>j)&1){
            rep(i, 0, n){
                to[i].first = to[i].first+dp[j][to[i].second].first;
                to[i].second = dp[j][to[i].second].second;
            }
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        // cout << to[i].first << ' ' << to[i].second << endl;
        ll tmp = to[i].first*n+to[i].second-i;
        chmin(tmp, (m-1)*n+(n-i));
        chmax(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}