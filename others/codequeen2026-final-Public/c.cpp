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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<vector<ll>> h(n);
    rep(i, 0, n){
        int c; cin >> c; c--;
        ll v; cin >> v;
        h[c].push_back(v);
    }
    vector<ll> cand;
    rep(i, 0, n){
        sort(h[i].rbegin(), h[i].rend());
        rep(j, 0, min(k/2, (int)h[i].size())){
            cand.push_back(h[i][j]);
        }
    }
    sort(cand.rbegin(), cand.rend());
    if(cand.size() < k){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    rep(i, 0, k) ans += cand[i];
    cout << ans << endl;
    
    return 0;
}