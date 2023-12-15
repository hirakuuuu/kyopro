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

// i桁目のビットが1かどうか
bool has_bit(ll x, int i){
    return (x>>i)&1;
}

// 長さnの静的なビット列に対して累積和ができるデータ構造
class BitCumulativeSum{

    // 64桁ごとに累積和を作る
    inline static constexpr int w = 64;

    vector<uint64_t> block; // ビット列をwごとに保持
    vector<int> sum;  // 累積和

public:
    BitCumulativeSum() = default;
    BitCumulativeSum(int n) : block(n/w+1, 0), sum(1, 0) {
        sum.reserve(block.size()+1); // 事前に要素数分のメモリを確保しておく（このサイズになっているわけではない）
    }

    // i桁目のビットを立てる
    void set(int i) {
        block[i/w] |= 1LL<<(i%w);
    }

    // 累積和を作成
    void build(){
        for(const auto &b: block){
            // popcount : 2進数表記で1の数を数える
            sum.push_back(sum.back()+__builtin_popcountll(b));
        }
    }

    // [0, r) 桁までの1の個数
    int rank1(int r) const {
        return sum[r/w] + __builtin_popcountll(block[r/w] & ((1LL<<(r%w))-1));
    }

    // [0, r) 桁まででの0の個数
    int rank0(int r) const {
        return r-rank1(r);
    }

};

// 本題
class WaveletMatrix {
    int n, sigma;
    vector<BitCumulativeSum> bv;

public:
    WaveletMatrix(vector<ll> v) : n((int)v.size()){
        // sigmaを決定する
        ll mx = 0;
        for(auto &x: v){
            assert(x >= 0);
            mx = max(mx, x);
        }
        sigma = 0;
        while((1LL<<sigma)-1 < mx) sigma++;

        // 行列の構築
        bv.assign(sigma, n);
        vector<ll> nxt_v(n);
        // 上位の桁から構築していく
        for(int h = sigma-1; h >= 0; h--){
            auto &B = bv[h]; // h桁目に対応するビットの累積和（ただし0の個数を数える）

            // ｖでｈ桁目が0の要素を左に、1の要素を右に寄せる
            int l = 0, r = n-1;
            // 1の方を寄せる
            for(int i = n-1; i >= 0; i--){
                if(has_bit(v[i], h)){
                    B.set(i);
                    nxt_v[r--] = v[i];
                }
            }

            B.build(); // 累積和を構築

            // 0の方も寄せる
            for(int i = 0; i < n; i++){
                if(!has_bit(v[i], h)){
                    nxt_v[l++] = v[i];
                }
            }
            swap(v, nxt_v);
        }
    }

    // [l, r) でk番目に小さい数（0-indexed）
    int kth_smallest(int l, int r, int k) const {
        assert(0 <= k && k < n);
        uint32_t res = 0;
        // 上位の桁から0か1を決定していく
        for(int h = sigma-1; h >= 0; h--){
            const auto &B = bv[h];
            int zero_cnt = B.rank0(r)-B.rank0(l); // 区間のビット0の個数
            if(k >= zero_cnt){
                // h桁目が1の場合
                res |= 1<<h;
                k -= zero_cnt;
                // 区間の更新
                // h桁目が0の要素が左、1の要素が右によっていることを利用する
                l = B.rank0(n)+B.rank1(l);
                r = B.rank0(n)+B.rank1(r);
            }else{
                // h桁目が0の場合
                l = B.rank0(l);
                r = B.rank0(r);
            }
        }
        return res;
    }

    // [l, r) でk番目に小さい数（0-indexed）
    int kth_largest(int l, int r, int k) const {
        assert(0 <= r-l-k+1 && r-l-k+1 < n);
        return kth_smallest(l, r, r-l-k+1);   
    }

    // [0, r) でu未満の値の個数
    ll range_freq(int r, ll u){
        assert(u >= 0);
        if(u >= (1LL<<sigma)) return r;

        int l = 0, ret = 0;
        for(int h = sigma-1; h >= 0; --h){
            auto &B = bv[h];
            if (has_bit(u, h)){
                // h桁目が1の場合
                ret += B.rank0(r)-B.rank0(l); // 区間に属しているh桁目が0の要素はu未満
                l = B.rank0(n)+B.rank1(l);
                r = B.rank0(n)+B.rank1(r);
            }else{
                // h桁目が0の場合
                l = B.rank0(l);
                r = B.rank0(r);
            }
        }

        return ret;
    }

    // [l, r) でu未満の値の個数
    ll range_freq(int l, int r, ll u){
        assert(u >= 0);
        return range_freq(r, u) - range_freq(l, u);
    }

    // [l, r) でd以上u未満の値の個数
    ll range_freq(int l, int r, ll d, ll u){
        assert(d >= 0 && u >= 0);
        return range_freq(l, r, u) - range_freq(l, r, d);
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<ll> u(n), d(n);
    rep(i, 0, n) cin >> u[i] >> d[i];

    WaveletMatrix wm_u(u);
    WaveletMatrix wm_d(d);
    rep(i, 0, q){
        int l, r, t; cin >> l >> r >> t;
        l--;
        cout << wm_u.range_freq(l, r, t+1)-wm_d.range_freq(l, r, t) << '\n';
    }

    return 0;
}