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
// https://atcoder.jp/contests/abc334/tasks/abc334_b

int main(){
    ll a, m, l, r; cin >> a >> m >> l >> r;
    ll pos = a%m;
    ll lm = (l%m+m)%m, rm = (r%m+m)%m;
    pos = (pos-lm+m)%m, rm = (rm-lm+m)%m;
    lm = 0;
    ll ans = (r-l+1)/m;
    if((r-l+1)%m != 0 && pos <= (r-l+1)%m-1) ans++;
    cout << ans << endl;

    
    return 0;
}