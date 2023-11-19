#include <bits/stdc++.h>
using namespace std;

/*
moのアルゴリズム
以下の3つを満たしている問題を解くのに使える
- 配列の要素が不変
- クエリを先読みできる
- 区間の結果から、区間を1つずらした結果をO(1)で求められる

流れ
区間を sqrt(Q) 個のブロックに分割する.
全てのクエリを, それぞれのクエリの左端のブロックで昇順ソート. 左端のブロックが同じもの同士では, 右端の値でソートする. （左端のブロックの位置の偶奇で昇順ソート, 降順ソートに分けると定数倍がよくなる）
クエリごとに左端と右端を尺取りのように移動させて, 区間を伸縮させる.

計算量は O(N*sqrt(Q)).
*/

class Mo
{
private:
    int n;
    vector<pair<int, int>> lr;

public:
    explicit Mo(int n) : n(n) {}

    // 区間を追加
    void add(int l, int r) {
        lr.emplace_back(l, r);
    }

    // クエリをブロックごとに答えていく
    template< typename AL, typename AR, typename EL, typename ER, typename O >
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
        int q = (int) lr.size();
        int bs = n / min<int>(n, sqrt(q));
        vector< int > ord(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
        int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
        if(ablock != bblock) return ablock < bblock;
        return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
        });
        int l = 0, r = 0;
        for(auto idx : ord) {
        while(l > lr[idx].first) add_left(--l);
        while(r < lr[idx].second) add_right(r++);
        while(l < lr[idx].first) erase_left(l++);
        while(r > lr[idx].second) erase_right(--r);
        out(idx);
        }
    }

    template< typename A, typename E, typename O >
    void build(const A &add, const E &erase, const O &out) {
        build(add, add, erase, erase, out);
    }
};

int main(){
    int N;
    cin >> N;
    vector< int > A(N);
    for(auto &a: A) cin >> a;
    int Q;
    cin >> Q;
    Mo mo(N);
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        mo.add(a - 1, b);
    }
    vector< int > cnt(1000001), ans(Q);
    int sum = 0;
    auto add = [&](int i) {
        if(cnt[A[i]]++ == 0) ++sum;
    };
    auto erase = [&](int i) {
        if(--cnt[A[i]] == 0) --sum;
    };
    auto out = [&](int q) {
        ans[q] = sum;
    };
    mo.build(add, erase, out);
    for(auto &p: ans) cout << p << "\n";

    return 0;
}