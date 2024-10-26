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
    ll n, m; cin >> n >> m;
    set<pair<ll, ll>> ng;
    
    vector<int> di = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dj = {1, 2, 2, 1, -1, -2, -2, -1};
    rep(i, 0, m){
        ll a, b; cin >> a >> b;
        ng.insert({a, b});
        rep(k, 0, 8){
            if(inr(1, a+di[k], n+1) && inr(1, b+dj[k], n+1)){
                ng.insert({a+di[k], b+dj[k]});
            }
        }
    }
    ll ans = n*n;
    ans -= ng.size();
    cout << ans << endl;
    return 0;
}