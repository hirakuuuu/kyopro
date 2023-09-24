#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
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

int main(){
    ll n, m, q; cin >> n >> m >> q;
    vector<pair<ll, ll>> vw(n);
    rep(i, 0, n) cin >> vw[i].second >> vw[i].first;
    sort(vw.begin(), vw.end());
    reverse(vw.begin(), vw.end());
    vector<ll> x(m);
    rep(i, 0, m) cin >> x[i];

    while(q--){
        ll l, r; cin >> l >> r;
        l--, r--;
        multiset<ll> s;
        rep(i, 0, m){
            if(l <= i && i <= r) continue;
            s.insert(x[i]);
        }
        ll ans = 0;
        rep(i, 0, n){
            auto itr = s.lower_bound(vw[i].second);
            if(itr == s.end()) continue;
            ans += vw[i].first;
            s.erase(itr);
        }
        cout << ans << endl;
    }
    
    
    return 0;
}