#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc004/tasks/arc004_3

bool calc(ll n, ll x, ll y){
    if(n%y == 0 and n*(n+1)/2 > n/y*x  and n*(n+1)/2 <= n/y*x+n) return true;
    else return false;
}

int main(){
    string s; cin >> s;
    ll x = 0, y = 0;
    bool f = false;
    for(auto ss: s){
        if(ss == '/') f = true;
        else if(!f) x = 10*x+(ss-'0');
        else y = 10*y+(ss-'0');
    }
    ll z = gcd(x, y);
    x /= z, y /= z;

    ll n = (2*x)/y;
    f = false;
    rep(i, 0, 2){
        if(calc(n, x, y)){
            f = true;
            cout << n << ' ' << n*(n+1)/2-(n/y)*x << endl;
        }
        n++;
    }
    if(!f) cout << "Impossible" << endl;
    return 0;
}