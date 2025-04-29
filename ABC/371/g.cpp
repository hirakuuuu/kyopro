#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

//多倍長整数//
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using lll = mp::cpp_int;

#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double



// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

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
inline lll mod(lll a, lll m) {
    return (a % m + m) % m;
}

inline lll mul(lll a, lll b, lll m) {
    a = mod(a, m); b = mod(b, m);
    if (b == 0) return 0;
    lll res = mul(mod(a + a, m), b>>1, m);
    if (b & 1) res = mod(res + a, m);
    return res;
}

// 拡張ユークリッドの互除法
// ap+bq=gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします。
lll extGCD(lll a, lll b, lll &p, lll &q){
    if (b == 0) {
        p = 1;
        q = 0;
        return a;
    }
    lll d = extGCD(b, a%b, q, p);
    q -= a/b*p;
    return d;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x = r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<lll, lll> chineseRem(const vector<lll> &b, const vector<lll> &m){
    lll r = 0, M = 1;
    rep(i, 0, (int)b.size()){
        lll p, q;
        lll d = extGCD(M, m[i], p, q); // p is inv of m1/d (mod. m[i]/d)
        if((b[i] - r) % d != 0) return {0, -1};
        lll tmp = mul(((b[i] - r) / d), p, (m[i] / d));
        r += M * tmp;
        M *= m[i] / d;
    }
    return {mod(r, M), M};
}


int main(){
    int n; cin >> n;
    vector<int> p(n), a(n);
    rep(i, 0, n) cin >> p[i], p[i]--;
    rep(i, 0, n) cin >> a[i], a[i]--;

    vector<vector<pair<int, int>>> q;
    vector<bool> seen(n);
    rep(i, 0, n){
        if(seen[a[i]]) continue;
        q.push_back({});
        q.back().push_back({a[i], 0});
        seen[a[i]] = true;
        int val = a[p[i]], pos = p[i];
        int r = 1;
        while(!seen[val]){
            q.back().push_back({val, r});
            seen[val] = true;
            val = a[p[pos]], pos = p[pos];
            r++;
        }
    }

    rep(i, 0, q.size()){
        sort(q[i].begin(), q[i].end(), [&](auto x, auto y){
            return x.first < y.first;
        });
    }

    vector<lll> M = {q[0].size()}, R = {q[0][0].second};
    vector<int> r(q.size());
    vector<int> rotate(n);
    r[0] = q[0][0].second;
    for(auto [x, y]: q[0]){
        rotate[x] = r[0];
    }
    rep(i, 1, q.size()){
        for(auto [x, y]: q[i]){
            M.push_back(q[i].size());
            R.push_back(y);
            pair<lll, lll> res = chineseRem(R, M);
            if(res.second != -1){
                R.pop_back();
                M.pop_back();
                R.push_back(res.first);
                M.push_back(res.second);
                r[i] = y;
                break;
            }
            M.pop_back();
            R.pop_back();
        }

        for(auto [x, y]: q[i]){
            rotate[x] = r[i];
        }
    }


    vector<vector<int>> dp(30, vector<int>(n));
    rep(i, 0, n){
        dp[0][i] = p[i];
    }
    rep(i, 1, 30){
        rep(j, 0, n){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    rep(i, 0, n){
        int cnt = rotate[a[i]];
        int pos = i;
        rep(k, 0, 30){
            if((cnt>>k)&1){
                pos = dp[k][pos];
            }
        }
        cout << a[pos]+1 << ' ';
    }
    cout << endl;




    
    return 0;
}