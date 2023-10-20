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
// https://atcoder.jp/contests/arc167/tasks/arc167_a

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> b(m);
    rep(i, 0, n-m) b[i] = a[n-m-1-i];
    rep(i, n-m, n) b[i-(n-m)] += a[i];
    
    ll ans = 0;
    rep(i, 0, m){
        ans += b[i]*b[i];
    }
    cout << ans << endl;
    

    
    return 0;
}