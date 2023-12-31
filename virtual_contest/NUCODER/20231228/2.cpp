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

// 問題
// 

int main(){
    ll n, m, p; cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> acc(m+1);
    rep(i, 0, m) acc[i+1] = acc[i]+b[i];
    ll ans = 0;
    rep(i, 0, n){
        ll pos = upper_bound(b.begin(), b.end(), p-a[i])-b.begin();
        ans += pos*a[i]+acc[pos]+p*(m-pos);
    }
    cout << ans << endl;
    
    return 0;
}