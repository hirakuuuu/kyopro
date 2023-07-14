#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}
#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif


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
// https://atcoder.jp/contests/abc144/tasks/abc144_e

int main(){
    ll n, k; cin >> n >> k;
    vector<int> a(n), f(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());


    ll ok = 1e18, ng = -1;
    while(ok-ng > 1){
        ll mid = ng+(ok-ng) / 2, cost = 0;
        vector<ll> tmp(n);
        rep(i, 0, n){
            tmp[i] = mid / f[i];
            cost += max(0LL, a[i]-tmp[i]);
        }

        if(cost <= k) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    debug(ng);
    return 0;
}