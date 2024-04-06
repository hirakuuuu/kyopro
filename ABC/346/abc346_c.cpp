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
// https://atcoder.jp/contests/abc346/tasks/abc346_c

int main(){
    ll n, k; cin >> n >> k;
    set<ll> a;
    rep(i, 0, n){
        ll b; cin >> b;
        a.insert(b);
    }
    ll ans = k*(k+1)/2;
    for(auto bb: a)  if(bb <= k) ans -= bb;
    cout << ans << endl;
    return 0;
}