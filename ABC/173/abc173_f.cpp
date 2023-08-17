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
// https://atcoder.jp/contests/abc173/tasks/abc173_f

int main(){
    ll n; cin >> n;
    ll total = 0;
    rep(i, 1, n+1){
        total += i*(n+1-i);
    }

    rep(i, 0, n-1){
        ll u, v; cin >> u >> v;
        if(u > v) swap(u, v);

        total -= u*(n-v+1);
    }
    cout << total << endl;
    
    return 0;
}