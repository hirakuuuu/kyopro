#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    ll x, y; cin >> x >> y;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    int ans = 0;
    ll tmp = 0, e = 0;
    while(true){
        ll nxt = -1;
        if(e == 0){
            auto itr = lower_bound(a.begin(), a.end(), tmp);
            if(itr == a.end()) break;
            nxt = *itr;
            tmp = nxt+x;
        }else{
            auto itr = lower_bound(b.begin(), b.end(), tmp);
            if(itr == b.end()) break;
            nxt = *itr;
            tmp = nxt+y;
            ans++;
        }
        e = 1-e;
    }
    cout << ans << endl;
    
    return 0;
}