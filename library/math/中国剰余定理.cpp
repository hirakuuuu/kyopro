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

/*
中国剰余定理 :
    m1とm2を互いに素な正の整数とする。
        x ≡ b1 (mod. m1)
        x ≡ b2 (mod. m2)
    を満たす整数 x が 0 以上 m1, m2 未満にただ1つ存在する。

    特にそれをｒとすると
        x ≡ b1 (mod. m1), x ≡ b2 (mod. m2)
        ↔ x ≡ r (mod. m1m2)
    が成立する。

アルゴリズム : 
二元の場合 : 
    x ≡ b1 (mod. m1), x ≡ b2 (mod. m2) の場合を解く。
    d = gcd(m1, m2) として、拡張ユークリッドの互除法によって
    m1*p+m2*q = d を満たす (p, q) を求め、
    x = b1+m1((b2-b1)/d)*p とすればよい。
    ( 
        b1 = b2 (mod. gcd(m1, m2)) より、b2-b1はdで割り切れる。
        s = ((b2-b1)/d) とおくと、m1*p+m2*q = d より、 
        s*m1*p+s*m2*q = b2-b1 
        →　s*m1*p+b1 = -s*m2*q+b2     
        x=b1+s*m1*p(=b2−s*m2*q) とおくと、
        x ≡ b1 (mod. m1), x ≡ b2 (mod. m2) が成り立っていることが分かる。
    )
*/

// 2元の場合
// 負の数にも対応した mod 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

inline long long mul(long long a, long long b, long long m) {
    a = mod(a, m); b = mod(b, m);
    if (b == 0) return 0;
    long long res = mul(mod(a + a, m), b>>1, m);
    if (b & 1) res = mod(res + a, m);
    return res;
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
        ll tmp = mul(((b[i] - r) / d), p, (m[i] / d));
        r += M * tmp;
        M *= m[i] / d;
    }
    return {mod(r, M), M};
}

int main(){
    pll res = chineseRem({2, 3}, {3, 5});
    cout << "x ≡ " << res.first << " (mod. "  << res.second << ")" << endl;
    
    return 0;
}