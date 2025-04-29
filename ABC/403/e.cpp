#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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

// Reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
#define ull unsigned long long 
// ハッシュの計算用
constexpr ull MASK30 = (1LL<<30)-1;
constexpr ull MASK31 = (1LL<<31)-1;
constexpr ull MOD = (1LL<<61)-1;
constexpr ull MASK61 = MOD;
constexpr ull POSITIVIZER = MOD * ((1<<3)-1);

// mod 2^61-1 を計算する関数
ull calcMod(ull x){
    ull xu = x>>61;
    ull xd = x&MASK61;
    ull res = xu+xd;
    if(res >= MOD) res -= MOD;
    return res;
}

// a*b mod 2^61-1 を返す関数
ull mul(ull a, ull b){
    ull au = a>>31, ad = a&MASK31;
    ull bu = b>>31, bd = b&MASK31;
    ull mid = ad*bu+au*bd;
    ull midu = mid>>30;
    ull midd = mid&MASK30;
    return au*bu*2+midu+(midd<<31)+ad*bd; // ハッシュの計算の時に mod をとった方が早くなる、
}

// a^b mod 2^61-1 を計算
ull modpow(ull a, ull b){
    ull res = 1;
    while(b > 0){
        if(b&1) res = calcMod(mul(res, a));
        a = calcMod(mul(a, a));
        b >>= 1;
    }
    return res;
}

// 基数を乱数を使って定める（ハック対策）
// Reference: https://trap.jp/post/1036/
ull randomized_base(ull r=37, ull max_s=127){
    ull k = rand()+max_s+1;
    while(gcd(MOD-1, k) != 1 || modpow(r, k) <= max_s){
        k = rand()+max_s+1;
    }
    return modpow(r, k);
}


template<typename Str>
class RollingHash {
    int n; // 文字列のサイズ
    ull base; // 基数 
    vector<ull> hash, powmemo; // ハッシュテーブルと基数の累乗のメモ


    // ハッシュテーブル構築
    void build(const Str &s){
        n = (int)s.size();
        hash.resize(n+1);
        powmemo.resize(n+1);
        powmemo[0] = 1;
        hash[0] = 0;
        for(int i = 0; i < n; i++){
            hash[i+1] = calcMod(mul(hash[i], base)+s[i]);
            powmemo[i+1] = calcMod(mul(powmemo[i], base));
        }
    }

public:
    RollingHash(const Str &s, ull _base=0){
        if(_base != 0) base = _base;
        else base = randomized_base();
        build(s);
    }
    
    // 開区間 [l, r) の hash 値を求める
    ull get(int l, int r = -1){
        if(r == -1) r = n;
        assert(l <= r);
        if(l == r) return 0LL;
        return calcMod(hash[r] + POSITIVIZER - mul(hash[l], powmemo[r-l]));
    }

    // hash a+b を求める（b の文字列としてのサイズが必要）
    ull unite(ull a, ull b, int bsize){
        return calcMod(mul(a, powmemo[bsize])+b);
    }

    // 開区間 [l1, r1) と ハッシュテーブル b の開区間 [l2, r2) における最長共通接頭辞
    int LCP(const RollingHash &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1) {
            int mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};

int main(){
    ull b = randomized_base(); // 基数を固定する
    
    int q; cin >> q;
    vector<pair<int, string>> query(q);
    rep(i, 0, q){
        int t; cin >> t;
        string s; cin >> s;
        query[i] = {t, s};
    }
    map<ull, int> x;
    rep(i, 0, q){
        auto [t, s] = query[i];
        if(t == 1){
            RollingHash<string> tab(s, b);
            if(!x.count(tab.get(0, (int)s.size()))) x[tab.get(0, (int)s.size())] = i;
        }
    }

    vector<int> ans(q+1);
    rep(i, 0, q){
        auto [t, s] = query[i];
        if(t == 2){
            RollingHash<string> tab(s, b);
            int mi = q;
            rep(j, 1, (int)s.size()+1){
                if(x.count(tab.get(0, j))) chmin(mi, x[tab.get(0, j)]);
            }
            // cout << s << ' ' << i << ' ' << mi << endl;
            if(i < mi){
                ans[i] += 1;
                ans[mi] -= 1;
            }
        }
    }
    rep(i, 0, q){
        cout << ans[i] << endl;
        ans[i+1] += ans[i];
    }
    
    return 0;
}