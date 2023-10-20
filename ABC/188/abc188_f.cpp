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
// https://atcoder.jp/contests/abc188/tasks/abc188_f

map<ll, ll> memo;
ll f(ll x, ll y){
    if(memo.find(y) != memo.end()) return memo[y];

    if(y == 1) return memo[y] = abs(x-y);
    else if(y%2) return memo[y] =min(abs(x-y), min(f(x, (y+1)/2), f(x, (y-1)/2))+2);
    else return memo[y] = min(abs(x-y), f(x, y/2)+1);
}

int main(){
    ll x, y; cin >> x >> y;
    if(y <= x){
        cout << x-y << endl;
    }else{
        cout << f(x, y) << endl;
    }
    
    
    return 0;
}
