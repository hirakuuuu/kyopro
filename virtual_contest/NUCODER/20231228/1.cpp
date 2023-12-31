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
    ll n, x; cin >> n >> x;
    vector<ll> a(n), b(n), ab(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        ab[i] = a[i]+b[i];
    }
    vector<ll> acc(n+1);
    ll ans = a[0]+b[0]*x;
    ll min_b = b[0];
    acc[0] = a[0]+b[0];
    rep(i, 1, n){
        chmin(min_b, b[i]);
        ll tmp = acc[i-1]+a[i]+b[i]+min_b*(x-i-1);
        chmin(ans, tmp);
        acc[i] = acc[i-1]+a[i]+b[i];
    }
    cout << ans << endl;

    
    return 0;
}