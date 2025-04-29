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
    ll n, x, d; cin >> n >> x >> d;

    if(d == 0){
        if(x == 0) cout << 1 << endl;
        else cout << n+1 << endl;
        return 0;
    }

    if(d < 0){
        x += (n-1)*d;
        d = -d;
    }

    ll g = abs(gcd(x, d));
    x /= g, d /= g;
    unordered_map<ll, set<pair<ll, ll>>> mp;
    for(ll i = 0; i <= n; i++){
        // |S| = i
        ll m = (x*i)%d;
        if(m < 0) m += d;
        
        ll l = i*(i-1)/2, r = i*(2*(n-1)-(i-1))/2;
        l += (x*i-m)/d, r += (x*i-m)/d;

        // mp[m] に {l, r} を挿入
        ll mi = l, mx = r+1;
        auto itr = mp[m].lower_bound({mi, mx});
        if(itr != mp[m].begin()) itr = prev(itr);

        while(itr != mp[m].end()){
            auto [pl, pr] = *itr;
            if(pr <= mi){
                itr++;
                continue;
            }
            if(mx <= pl){
                break;
            }

            chmin(mi, pl);
            chmax(mx, pr);
            mp[m].erase(itr++);
        }
        mp[m].insert({mi, mx});
    }

    ll ans = 0;
    for(auto [_, val]: mp){
        for(auto [l, r]: val) ans += r-l;
    }
    cout << ans << endl;
    
    return 0;
}