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
// https://atcoder.jp/contests/abc340/tasks/abc340_c

map<ll, ll> memo;
ll f(ll n){
    if(n <= 1) return 0; 
    if(memo[n]) return memo[n];
    return memo[n] = n+f(n/2)+f((n+1)/2);
}

int main(){
    ll n; cin >> n;
    cout << f(n) << endl;

    
    return 0;
}