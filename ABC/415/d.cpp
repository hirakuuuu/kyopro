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
    vector<pair<ll, ll>> ab(m);
    rep(i, 0, m){
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end(), [](auto c1, auto c2){
        return (c1.first-c1.second) < (c2.first-c2.second);
    });

    ll tmp = n;
    ll ans = 0;
    rep(i, 0, m){
        if(tmp < ab[i].first) continue;
        ll c = ab[i].first-ab[i].second;
        ll ng = 0, ok = (tmp+c-1)/c;
        while(ok-ng > 1){
            ll mid = (ok+ng)/2;
            if(tmp-c*mid >= ab[i].first) ng = mid;
            else ok = mid; 
        }
        tmp -= c*ok;
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}