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
    int n, l; cin >> n >> l;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> w;
    rep(i, 0, l){
        if((ll)i*(l-i) <= 200000 && (ll)i*(l-i) > 0) w.push_back((ll)i*(l-i));
        if((ll)i*(l-i) >= (ll)(i+1)*(l-i-1)) break;
    }
    vector<ll> ans(200005, INF);
    ans[0] = 0;
    rep(i, 1, 200005){
        for(auto ww: w){
            if(i-ww >= 0 && ans[i-ww] != INF) chmin(ans[i], ans[i-ww]+1);
        }
    }
    rep(i, 0, n){
        if(ans[a[i]] == INF) cout << -1 << endl;
        else cout << ans[a[i]] << endl;
    }

    
    return 0;
}