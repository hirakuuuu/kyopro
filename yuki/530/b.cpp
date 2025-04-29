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

    vector<pair<ll, ll>> p(4);
    rep(i, 0, 4) cin >> p[i].second;
    rep(i, 0, 4) cin >> p[i].first;
    sort(p.begin(), p.end());

    ll t; cin >> t;
    ll ans = 0;
    rep(i, 0, 4){
        if(p[i].first*p[i].second <= t){
            t -= p[i].first*p[i].second;
            ans += p[i].second;
        }else{
            ans += t/p[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}