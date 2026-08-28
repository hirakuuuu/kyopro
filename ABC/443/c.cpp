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
    ll n, t; cin >> n >> t;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<pair<ll, ll>> event;
    rep(i, 0, n){
        event.push_back({a[i], 0});
        if(a[i]+100 <= t) event.push_back({a[i]+100, 1});
    }
    sort(event.begin(), event.end());
    
    ll ans = 0;
    int tmp = 1;
    ll pre = 0;
    ll close = -1;
    for(auto [time, k]: event){
        if(k == 0){
            if(tmp){
                ans += time-pre;
                close = time;
            }
            tmp = 0;
        }else{
            if(!tmp && time-close == 100){
                pre = time;
                tmp = 1;
            }
        }
        // cout << pre << ' ' << time << ' ' << ans << endl;
    }
    if(tmp) ans += t-pre;
    cout << ans << endl;

    return 0;
}