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
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    rep(i, 0, n) cin >> b[i];
    sort(b.rbegin(), b.rend());
    rep(i, 0, n) cin >> c[i];
    sort(c.rbegin(), c.rend());

    map<tuple<int, int, int>, bool> checked;
    priority_queue<pair<ll, tuple<int, int, int>>> que;
    que.push({a[0]*b[0]+b[0]*c[0]+c[0]*a[0], {0, 0, 0}});
    checked[{0, 0, 0}] = true;
    ll ans = 0;
    rep(_, 0, k){
        auto [val, id] = que.top(); que.pop();
        auto [ia, ib, ic] = id;
        // cout << ia << ' ' << ib << ' ' << ic << endl;
        // cout << val << endl;
        ans = val;
        if(ia+1 < n && !checked[{ia+1, ib, ic}]){
            que.push({a[ia+1]*b[ib]+b[ib]*c[ic]+c[ic]*a[ia+1], {ia+1, ib, ic}});
            checked[{ia+1, ib, ic}] = true;
        }
        if(ib+1 < n && !checked[{ia, ib+1, ic}]){
            que.push({a[ia]*b[ib+1]+b[ib+1]*c[ic]+c[ic]*a[ia], {ia, ib+1, ic}});
            checked[{ia, ib+1, ic}] = true;
        }
        if(ic+1 < n && !checked[{ia, ib, ic+1}]){
            que.push({a[ia]*b[ib]+b[ib]*c[ic+1]+c[ic+1]*a[ia], {ia, ib, ic+1}});
            checked[{ia, ib, ic+1}] = true;
        }
    }
    cout << ans << endl;

    return 0;
}