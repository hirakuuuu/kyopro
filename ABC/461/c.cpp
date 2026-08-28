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
    int n, k, m; cin >> n >> k >> m;
    vector<pair<int, int>> cv(n);
    rep(i, 0, n){
        int c, v; cin >> c >> v;
        c--;
        cv[i] = {v, c};
    }
    sort(cv.rbegin(), cv.rend());
    vector<int> mx(n, -1);
    vector<int> rest;
    rep(i, 0, n){
        if(mx[cv[i].second] == -1){
            mx[cv[i].second] = cv[i].first;
        }else{
            rest.push_back(cv[i].first);
        }
    }
    sort(mx.rbegin(), mx.rend());

    ll ans = 0;
    rep(i, 0, m) ans += (ll)mx[i];
    rep(i, m, n){
        if(mx[i] == -1) continue;
        rest.push_back(mx[i]);
    }
    sort(rest.rbegin(), rest.rend());
    rep(i, 0, k-m) ans += (ll)rest[i];
    cout << ans << endl;

    return 0;
}