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
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    vector<ll> sum(n+1);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
        
    rep(i, 0, n) sum[i+1] = a[i]+sum[i];

    while(q--){
        ll x; cin >> x;
        ll cnt = upper_bound(a.begin(), a.end(), x)-a.begin();
        ll ans = (cnt*x-sum[cnt])+(sum[n]-sum[cnt]-(n-cnt)*x);
        cout << ans << '\n';
    }

    
    return 0;
}