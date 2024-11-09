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
constexpr int IINF = 1901001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template <int B> // B: 桁数
struct BitTrie {
    vector<array<int, 2>> to; // 辺
    vector<int> cnt; // 頂点に対応する個数
    BitTrie(): to(1) {}

    void add(int x){
        int v = 0; 
        for(int i = B-1; i >= 0; i--){
            int b = (x>>i)&1;
            if(!to[v][b]){
                to.push_back(array<int, 2>());
                to[v][b] = (int)to.size()-1;
            }
            v = to[v][b];
        }
    }

    int xor_min(int x){ // trieに追加された値で x との xor の最小値
        int v = 0;
        int res = 0;
        for(int i = B-1; i >= 0; i--){
            int b = (x>>i)&1;
            if(!to[v][b]){
                b ^= 1;
                res ^= (1<<i);
            }
            v = to[v][b];
        }
        return res;
    }
};


int main(){
    int n; cin >> n;
    vector<ll> a(2*n);
    rep(i, 0, 2*n) cin >> a[i];
    sort(a.begin(), a.end());

    auto f = [&](auto self, int l, int r, ll d) -> ll {
        // cout << l << ' ' << r << ' ' << d << endl;
        assert(((r-l)&1) == 0);
        if(l == r) return -1;
        if(d == 0) return 0;

        vector<vector<ll>> bit(2);
        rep(i, l, r){
            if((a[i]&d) >= 1) bit[1].push_back(a[i]);
            else bit[0].push_back(a[i]);
            // bit[(a[i]&d >= 1)].push_back(a[i]);
        }

        ll res = INF;
        if((bit[1].size())&1){
            // この桁はどのように選んでも１になる
            // ２つの集合から値を一つ選んで xor をとるときの最小値は bit_trie
            BitTrie<30> trie;
            for(auto b0: bit[0]) trie.add(b0);
            for(auto b1: bit[1]) chmin(res, trie.xor_min(b1));
        }else{
            // 区間を分割
            int m = l+bit[0].size();
            // cout << l << ' ' << m << ' ' << r << ' ' << d << endl;
            res = max(self(self, l, m, d>>1), self(self, m, r, d>>1));
        }
        return res;
    };

    cout << f(f, 0, 2*n, 1LL<<32) << endl;
    return 0;
}