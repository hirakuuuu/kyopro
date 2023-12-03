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
// https://atcoder.jp/contests/abc331/tasks/abc331_e

int main(){
    ll n, m, l; cin >> n >> m >> l;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    vector<pair<ll, ll>> bb(m);
    rep(i, 0, m){
        bb[i] = {b[i], i};
    }
    sort(bb.rbegin(), bb.rend());
    map<pair<ll, ll>, bool> hate;
    rep(i, 0, l){
        ll c, d; cin >> c >> d;
        c--, d--;
        hate[make_pair(c, d)] = true;
    }

    ll ans = 0;
    rep(i, 0, n){
        for(auto [c, ind]: bb){
            if(hate[{i, ind}]) continue;
            chmax(ans, a[i]+c);
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}