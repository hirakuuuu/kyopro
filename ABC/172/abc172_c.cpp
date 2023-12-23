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
// https://atcoder.jp/contests/abc172/tasks/abc172_c

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    vector<ll> acc_a(n+1), acc_b(m+1);
    rep(i, 0, n) acc_a[i+1] = acc_a[i]+a[i];
    rep(i, 0, m) acc_b[i+1] = acc_b[i]+b[i];

    int ans = 0;
    rep(i, 0, n+1){
        ll tmp = acc_a[i];
        if(tmp > k) continue;
        auto pos = upper_bound(acc_b.begin(), acc_b.end(), k-tmp)-acc_b.begin()-1;
        chmax(ans, i+pos);
    }
    cout << ans << endl;
    
    return 0;
}