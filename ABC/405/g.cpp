#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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

    vector<mint> fac(250005), inv(250005);
    fac[0] = 1;
    inv[0] = inv[1] = 1;
    rep(i, 1, 250005) fac[i] = fac[i-1]*i;
    rep(i, 2, 250005) inv[i] = mint(i).inv();

    int b = 500;
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }

    Mo mo(n);
    vector<int> x(q);
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        l--;
        mo.add(l, r);
        cin >> x[i];
        x[i]--;
    }
    vector<int> cnt(n);
    vector<int> cnt_b(n/b+1);
    vector<mint> bunbo(n, 1);
    vector<mint> bunbo_b(n/b+1, 1);
    vector<mint> ans(q);
    auto add = [&](int i) {
        cnt[a[i]]++;
        cnt_b[a[i]/b]++;
        bunbo[a[i]] *= inv[cnt[a[i]]];
        bunbo_b[a[i]/b] *= inv[cnt[a[i]]];
    };
    auto erase = [&](int i) {
        bunbo[a[i]] *= cnt[a[i]];
        bunbo_b[a[i]/b] *= cnt[a[i]];
        cnt[a[i]]--;
        cnt_b[a[i]/b]--;
    };
    auto out = [&](int q) {
        ans[q] = 1;
        int tot = 0, tmp = x[q]-1;
        mint tal = 1;
        while((tmp+b)%b < b-1){
            tot += cnt[tmp];
            tal *= bunbo[tmp];
            tmp--;
        }
        while(tmp > 0){
            tot += cnt_b[tmp/b];
            tal *= bunbo_b[tmp/b];
            tmp -= b;
        }
        // cout << q << ' ' << tot << ' ' << fac[tot].val() << endl;
        // cout << q << ' ' << tal.val()  << endl;
        // cout << tot << ' ' << fac[tot].val() << endl;
        ans[q] = fac[tot]*tal;
    };
    mo.build(add, erase, out);
    for(auto &p: ans) cout << p.val() << "\n";

    return 0;
}