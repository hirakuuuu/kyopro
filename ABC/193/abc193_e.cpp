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
// https://atcoder.jp/contests/abc193/tasks/abc193_e

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
    int t; cin >> t;
    while(t--){
        ll x, y, p, q; cin >> x >> y >> p >> q;
        ll ans = 9e18;
        // 停車中に起きる場合
        // (p+q)n - 2(x+y)m = x-p+i の整数解
        rep(i, 0, y){
            auto a = chineseRem({p, x+i}, {p+q, 2*(x+y)});
            if(a.second != -1) chmin(ans, a.first); 
        }
        // 起きている間に停車する場合
        // (p+q)n - 2(x+y)m = x-p-i の整数解
        rep(i, 0, q){
            auto a = chineseRem({p+i, x}, {p+q, 2*(x+y)});
            if(a.second != -1) chmin(ans, a.first); 
        }

        if(ans == (ll)9e18) cout << "infinity" << endl;
        else cout << ans << endl;
    }
    return 0;
}