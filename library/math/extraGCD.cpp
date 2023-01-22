#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
拡張ユークリッドの互除法 : 
    ax+by=gcd(a, b)を満たす(x, y)を求めるアルゴリズム。
    (a, b) に関する問題を (b, a%b) に関する問題に帰着することで再帰的に解く。
*/

// 返り値: a と b の最大公約数
// ax+by=gcd(a, b) を満たす (x, y) が格納される

ll extGCD(ll a, ll b, ll &x, ll &y){
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int main(){
    ll x, y;
    extGCD(111, 30, x, y);
    cout << x << ", " << y << endl;
    return 0;
}