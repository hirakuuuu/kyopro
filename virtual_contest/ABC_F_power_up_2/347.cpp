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

template <class T, T (*op)(T, T), T (*e)()> 
struct SegmentTree2D {
 private:
  int id(int h, int w) const { return h * 2 * W + w; }

 public:
  int H, W;
  vector<T> seg;

  SegmentTree2D(int h, int w) { init(h, w); }

  void init(int h, int w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, e());
  }

  // build にのみ呼ぶ
  void set(int h, int w, const T& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = op(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = op(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  T get(int h, int w) const { return seg[id(h + H, w + W)]; }
  T operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

  void update(int h, int w, const T& x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (int i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (int j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  T _inner_query(int h, int w1, int w2) {
    T res = e();
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = op(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = op(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  T query(int h1, int w1, int h2, int w2) {
    if (h1 >= h2 || w1 >= w2) return e();
    T res = e();
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = op(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = op(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

/*
build()の実行を忘れないように！！！
*/

using S = ll;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return LLONG_MIN;
}


int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, 0, n) rep(j, 0, n){
        cin >> a[i][j];
    }

    vector<vector<ll>> acc(n+1, vector<ll>(n+1));
    rep(i, 0, n){
        rep(j, 0, n){
            acc[i+1][j+1] = acc[i+1][j]+acc[i][j+1]-acc[i][j]+a[i][j];
        }
    }

    SegmentTree2D<S, op, e> seg(n-m+1, n-m+1);
    rep(i, 0, n-m+1){
        rep(j, 0, n-m+1){
            seg.set(i, j, acc[i+m][j+m]-acc[i][j+m]-acc[i+m][j]+acc[i][j]);
        }
    }
    seg.build();

    ll ans = 0;
    // 横並び３つ
    rep(r1, m, n-m+1){
        rep(r2, r1+m, n-m+1){
            if(r2+m >= n-m+1) break;
            ll c1 = seg.query(0, 0, n-m+1, r1);
            ll c2 = seg.query(0, r1, n-m+1, r2);
            ll c3 = seg.query(0, r2, n-m+1, n-m+1);
            chmax(ans, c1+c2+c3);
        }
    }
    // 縦並び３つ
    rep(r1, 1, n-m+1){
        rep(r2, r1+1, n-m+1){
            ll c1 = seg.query(0, 0, r1, n-m+1);
            ll c2 = seg.query(r1, 0, r2, n-m+1);
            ll c3 = seg.query(r2, 0, n-m+1, n-m+1);
            chmax(ans, c1+c2+c3);
        }
    }

    // 縦二つ横一つ

    return 0;
}