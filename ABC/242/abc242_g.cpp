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
// https://atcoder.jp/contests/abc242/tasks/abc242_g

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
    int n; cin >> n;
    Mo mo(n);

    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }

    int q; cin >> q;
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        mo.add(l-1, r);
    }

    vector<int> cnt(n), ans(q);
    int sum = 0;
    auto add = [&](int i) {
        cnt[a[i]]++;
        if(cnt[a[i]]%2 == 0) sum++;
    };
    auto erase = [&](int i) {
        cnt[a[i]]--;
        if(cnt[a[i]]%2 == 1) sum--;
    };
    auto out = [&](int i) {
        ans[i] = sum;
    };

    mo.build(add, erase, out);
    for(auto &p: ans) cout << p << '\n';

    return 0;
}