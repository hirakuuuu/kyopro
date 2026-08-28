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
    int n, k; cin >> n >> k;
    vector<ll> h(n);
    rep(i, 0, n) cin >> h[i];
    multiset<ll> ms;
    rep(i, 0, k) ms.insert(h[i]);
    ll ans = *ms.rbegin()-*ms.begin();
    rep(i, k, n){
        ms.erase(ms.find(h[i-k]));
        ms.insert(h[i]);
        chmax(ans, *ms.rbegin()-*ms.begin());
    }
    cout << ans << endl;
    return 0;
}