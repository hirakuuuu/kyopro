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
    ll n, c; cin >> n >> c;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> acc(n+1);
    rep(i, 0, n) acc[i+1] = acc[i]+a[i];
    ll ans = acc[n], sum = acc[n];
    if(c > 0){
        ll tmp = 0;
        rep(i, 1, n+1){
            chmax(ans, sum-(acc[i]-tmp)+(acc[i]-tmp)*c);
            chmin(tmp, acc[i]);
        }
    }else{
        ll tmp = 0;
        rep(i, 1, n+1){
            chmax(ans, sum-(acc[i]-tmp)+(acc[i]-tmp)*c);
            chmax(tmp, acc[i]);
        }
    }
    cout << ans << endl;
    return 0;
}