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
// https://atcoder.jp/contests/abc047/tasks/arc063_b

int main(){
    ll n, t; cin >> n >> t;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> profit(n);
    ll min_a = a[0];
    ll max_profit = 0; 
    rep(i, 1, n){
        chmin(min_a, a[i]);
        profit[i] = a[i]-min_a;
        chmax(max_profit, profit[i]);
    }

    ll ans = 0;
    rep(i, 0, n){
        if(profit[i] == max_profit) ans++;
    }
    cout << ans << endl;


    
    return 0;
}