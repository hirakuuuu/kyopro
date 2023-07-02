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
// https://atcoder.jp/contests/abc308/tasks/abc308_f

int main(){
    int n, m; cin >> n >> m;
    vector<ll> p(n);
    rep(i, 0, n) cin >> p[i];
    vector<pll> c(m);
    rep(i, 0, m) cin >> c[i].second;
    rep(i, 0, m) cin >> c[i].first;

    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    set<pll> price;  
    ll ans = 0;
    rep(i, 0, n){
        ans += p[i];
        price.insert({p[i], i});
    }

    rep(i, 0, m){
        const auto [d, l] = c[i];
        auto itr = price.lower_bound({l, 0});
        if(itr == price.end()) continue;
        ans -= d;
        price.erase(itr);
    }

    cout << ans << endl;


    return 0;
}