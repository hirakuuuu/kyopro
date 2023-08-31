#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc210/tasks/abc210_e

int main(){
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> e(m);
    rep(i, 0, m) cin >> e[i].second >> e[i].first;
    sort(e.begin(), e.end());
    map<ll, bool> seen;

    ll n_ = n, ans = 0;
    rep(i, 0, m){
        auto [c, a] = e[i];
        if(seen[a]) continue;
        seen[a] = true;
        ans += (n_ - gcd(n_, a))*c;
        n_ = gcd(n_, a);
        if(n_ == 1) break;
    }

    if(n_ == 1) cout << ans << endl;
    else cout << -1 << endl;

    
    return 0;
}