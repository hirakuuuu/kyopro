#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
// https://atcoder.jp/contests/arc169/tasks/arc169_c

ll f(ll a, ll b){
    ll oa = 0;
    while(a){
        oa++;
        a /= 10;
    }
    ll ob = 0;
    while(b){
        ob++;
        b /= 10;
    }
    return max(oa, ob);
}

int main(){
    ll n; cin >> n;
    vector<pair<ll, ll>> y;
    rep(i, 1, sqrt(n)+1){
        if(n%i == 0){
            ll l = i, r = n/i;
            if(l > r) continue;
            y.push_back({l, r});
        }
    }

    ll ans = INF;
    for(auto [a, b]: y) chmin(ans, f(a, b));
    cout << ans << endl;

    return 0;
}