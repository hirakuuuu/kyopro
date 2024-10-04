#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> pos(n);
    rep(i, 0, n){
        a[i]--;
        pos[a[i]].push_back(i);
    }
    rep(i, 0, n){
        pos[i].push_back(n);
    }
    vector<int> id(n);

    ll ans = 0;
    rep(r, 0, n){
        ans += (ll)(r+1)*(pos[a[r]][id[a[r]]+1]-pos[a[r]][id[a[r]]]);
        id[a[r]]++;
    }
    cout << ans << endl;
    return 0;
}