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

/*
- 1000000000 個の配列が必要
- 動的セグ木で解決（必要になったらノードを用意するイメージ）
- 偶奇で分けて総和を取るやつは個数を持っておくとモノイドが作れる
*/

template <class S, S (*op)(S, S), S (*e)()> class dynamic_segtree {
public:
    dynamic_segtree(size_t n) : n(n), root(nullptr) {}

    void set(size_t p, S x) {
        assert(p < n);
        set(root, 0, n, p, x);
    }

    S get(size_t p) const {
        assert(p < n);
        return get(root, 0, n, p);
    }

    S prod(size_t l, size_t r) const {
        assert(l <= r && r <= n);
        return prod(root, 0, n, l, r);
    }

    S all_prod() const { return root ? root->product : e(); }

    void reset(size_t l, size_t r) {
        assert(l <= r && r <= n);
        return reset(root, 0, n, l, r);
    }

    template <bool (*f)(S)> size_t max_right(size_t l) const {
        return max_right(l, [](S x) { return f(x); });
    }

    template <class F> size_t max_right(size_t l, const F& f) const {
        assert(l <= n);
        S product = e();
        assert(f(product));
        return max_right(root, 0, n, l, f, product);
    }

    template <bool (*f)(S)> size_t min_left(size_t r) const {
        return min_left(r, [](S x) { return f(x); });
    }

    template <class F> size_t min_left(size_t r, const F& f) const {
        assert(r <= n);
        S product = e();
        assert(f(product));
        return min_left(root, 0, n, r, f, product);
    }

private:
    struct node;
    using node_ptr = std::unique_ptr<node>;

    struct node {
        size_t index;
        S value, product;
        node_ptr left, right;

        node(size_t index, S value)
            : index(index),
                value(value),
                product(value),
                left(nullptr),
                right(nullptr) {}

        void update() {
            product = op(op(left ? left->product : e(), value),
                            right ? right->product : e());
        }
    };

    const size_t n;
    node_ptr root;

    void set(node_ptr& t, size_t a, size_t b, size_t p, S x) const {
        if (!t) {
            t = std::make_unique<node>(p, x);
            return;
        }
        if (t->index == p) {
            t->value = x;
            t->update();
            return;
        }
        size_t c = (a + b) >> 1;
        if (p < c) {
            if (t->index < p) std::swap(t->index, p), std::swap(t->value, x);
            set(t->left, a, c, p, x);
        } else {
            if (p < t->index) std::swap(p, t->index), std::swap(x, t->value);
            set(t->right, c, b, p, x);
        }
        t->update();
    }

    S get(const node_ptr& t, size_t a, size_t b, size_t p) const {
        if (!t) return e();
        if (t->index == p) return t->value;
        size_t c = (a + b) >> 1;
        if (p < c) return get(t->left, a, c, p);
        else return get(t->right, c, b, p);
    }

    S prod(const node_ptr& t, size_t a, size_t b, size_t l, size_t r) const {
        if (!t || b <= l || r <= a) return e();
        if (l <= a && b <= r) return t->product;
        size_t c = (a + b) >> 1;
        S result = prod(t->left, a, c, l, r);
        if (l <= t->index && t->index < r) result = op(result, t->value);
        return op(result, prod(t->right, c, b, l, r));
    }

    void reset(node_ptr& t, size_t a, size_t b, size_t l, size_t r) const {
        if (!t || b <= l || r <= a) return;
        if (l <= a && b <= r) {
            t.reset();
            return;
        }
        size_t c = (a + b) >> 1;
        reset(t->left, a, c, l, r);
        reset(t->right, c, b, l, r);
        t->update();
    }

    template <class F>
    size_t max_right(const node_ptr& t, size_t a, size_t b,
                        size_t l, const F& f, S& product) const {
        if (!t || b <= l) return n;
        if (f(op(product, t->product))) {
            product = op(product, t->product);
            return n;
        }
        size_t c = (a + b) >> 1;
        size_t result = max_right(t->left, a, c, l, f, product);
        if (result != n) return result;
        if (l <= t->index) {
            product = op(product, t->value);
            if (!f(product)) return t->index;
        }
        return max_right(t->right, c, b, l, f, product);
    }

    template <class F>
    size_t min_left(const node_ptr& t, size_t a, size_t b,
                    size_t r, const F& f, S& product) const {
        if (!t || r <= a) return 0;
        if (f(op(t->product, product))) {
            product = op(t->product, product);
            return 0;
        }
        size_t c = (a + b) >> 1;
        size_t result = min_left(t->right, c, b, r, f, product);
        if (result != 0) return result;
        if (t->index < r) {
            product = op(t->value, product);
            if (!f(product)) return t->index + 1;
        }
        return min_left(t->left, a, c, r, f, product);
    }
};

using S = tuple<ll, ll, ll>;
S op(S a, S b) {
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;
    ll c1 = a1+b1;
    ll c2, c3;
    if(a1%2 == 1) c2 = a2+b3, c3 = a3+b2; 
    else c2 = a2+b2, c3 = a3+b3; 
    return {c1, c2, c3};
}
S e() {
    return {0LL, 0LL, 0LL};
}

int main(){
    int q; cin >> q;
    ll m = 1000000000;
    ll z = 0;

    dynamic_segtree<S, op, e> cnt(m+1);
    while(q--){
        ll y; cin >> y;
        ll x = (y+z)%m+1;

        auto [a1, a2, a3] = cnt.get(x);
        if(a1%2 == 0) a2 += x;
        else a3 += x;
        cnt.set(x, {a1+1, a2, a3});

        auto [x1, x2, x3] = cnt.all_prod();
        cout << x2 << endl;
        z = x2;
    }
    
    return 0;
}