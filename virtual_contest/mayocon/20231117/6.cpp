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
// 

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

ll f(ll n){
    return n*(n-1)*(n-2)/6;
}

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    Mo mo(n);
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        mo.add(l - 1, r);
    }
    vector<ll> cnt(200005), ans(q);
    ll sum = 0;
    auto add = [&](int i) {
        sum -= f(cnt[a[i]]);
        cnt[a[i]]++;
        sum += f(cnt[a[i]]);
    };
    auto erase = [&](int i) {
        sum -= f(cnt[a[i]]);
        cnt[a[i]]--;
        sum += f(cnt[a[i]]);
    };
    auto out = [&](int q) {
        ans[q] = sum;
    };
    mo.build(add, erase, out);
    for(auto &p: ans) cout << p << "\n";
    return 0;
}