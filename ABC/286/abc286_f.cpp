#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc286/tasks/abc286_f

// 2元の場合
// 負の数にも対応した mod 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// 拡張ユークリッドの互除法
// ap+bq=gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします。
ll extGCD(ll a, ll b, ll &p, ll &q){
    if (b == 0) {
        p = 1;
        q = 0;
        return a;
    }
    ll d = extGCD(b, a%b, q, p);
    q -= a/b*p;
    return d;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x = r (mod. m)
// 解なしの場合は (0, -1) をリターン
pll chineseRem(const vector<ll> &b, const vector<ll> &m){
    ll r = 0, M = 1;
    rep(i, 0, (int)b.size()){
        ll p, q;
        ll d = extGCD(M, m[i], p, q); // p is inv of m1/d (mod. m[i]/d)
        if((b[i] - r) % d != 0) return {0, -1};
        ll tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return {mod(r, M), M};
}

vector<ll> p = {4, 5, 7, 9, 11, 13, 17, 19, 23};

int main(){
    const ll m = 108;
    vector<ll> a(m);
    ll id = 0;
    for(const auto &pp: p){
        ll s = id+1;
        rep(i, 0, pp){
            a[id] = s+(pp-(s-id))%pp;
            id++;
        }
    }
    cout << m << endl;

    rep(i, 0, m){
        cout << a[i] << ' ';
    }
    cout << endl;

    vector<ll> r;
    vector<ll> b(m);
    rep(i, 0, m) cin >> b[i];
    id = 0;
    ll sm = 0;
    for(const auto &pp: p){
        sm += pp;
        r.push_back((1+(sm-b[id]))%pp);
        id += pp;
    }


    pll res = chineseRem(r, p);
    cout << res.first << endl;

    return 0;
}