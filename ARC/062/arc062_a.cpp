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
// https://atcoder.jp/contests/abc046/tasks/arc062_a

int main(){
    int n; cin >> n;
    ll ans = 1;
    vector<ll> t(n+1, 1), a(n+1, 1);
    rep(i, 1, n+1) cin >> t[i] >> a[i];
    rep(i, 1, n+1){
        ll tmp = max((t[i-1]+t[i]-1)/t[i], (a[i-1]+a[i]-1)/a[i]);
        t[i] *= tmp;
        a[i] *= tmp;
        if(ans%(t[i]+a[i]) == 0) continue;
        ans += (t[i]+a[i])-(ans%(t[i]+a[i]));
    }
    cout << ans << endl;
    
    return 0;
}