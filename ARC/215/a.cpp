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
    int t; cin >> t;
    while(t--){
        ll n, k, l; cin >> n >> k >> l;
        vector<ll> a(n);
        rep(i, 0, n){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = (int)a.size();

        vector<ll> d;
        rep(i, 1, n) d.push_back(a[i]-a[i-1]);
        sort(d.rbegin(), d.rend());

        ll ans = (a[0]+(l-a[n-1]))*(k-1)+max(a[0], l-a[n-1]);
        if(k == 1){
            rep(i, 0, (int)d.size()) chmax(ans, d[i]/2);
        }
        // cout << ans << endl;

        ll sum_d = 0;
        rep(i, 0, (int)d.size()){
            if(k-i-2 < 0) break;
            sum_d += d[i];
            ll tmp = (l-(a[n-1]-a[0])+sum_d)*(k-i-2)+max(a[0], l-a[n-1])+sum_d;
            chmax(ans, tmp);
            // cout << ans << endl;
        }

        cout << ans << endl;
    }
    return 0;
}