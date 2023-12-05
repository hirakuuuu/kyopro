#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Wavelet Matrix
- 長さｎの静的な配列ｖに対して色々な区間クエリを高速で解く(O(log max(v))) データ構造
  - 例えば、区間[l, r) でk番目に小さい値
  - 区間[l, r) でu未満の値の個数
  - この2つの応用で色々できる
- 元々データの持ち方が木であったが、行列にした方が実装楽じゃねとなったらしい

参考
https://acompany-ac.notion.site/231205_Wavelet-Matrix-cb5503e9cbf440b59424ad5967f510f1
*/



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
            sum.push_back(sum.back()+popcount(b));
        }
    }

    // [0, r) 桁までの1の個数
    int rank1(int r) const {
        return sum[r/w] + popcount(block[r/w] & ((1LL<<(r%w))-1));
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
    WaveletMatrix(vector<int> v) : n((int)v.size()){
        // sigmaを決定する
        int mx = 0;
        for(auto &x: v){
            assert(x >= 0);
            mx = max(mx, x);
        }
        sigma = 0;
        while((1LL<<sigma)-1 < mx) sigma++;

        // 行列の構築
        bv.assign(sigma, n);
        vector<int> nxt_v(n);
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
    int range_freq(int r, int u){
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
    int range_freq(int l, int r, int u){
        assert(u >= 0);
        return range_freq(r, u) - range_freq(l, u);
    }

    // [l, r) でd以上u未満の値の個数
    int range_freq(int l, int r, int d, int u){
        assert(d >= 0 && u >= 0);
        return range_freq(l, r, u) - range_freq(l, r, d);
    }
};

int main(){
    return 0;
}