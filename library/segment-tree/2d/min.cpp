#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    return min(a, b);
}
S e() {
    return LLONG_MAX;
}


// https://onlinejudge.u-aizu.ac.jp/problems/1068
int main(){
    while(true){
        int r, c, q; cin >> r >> c >> q;
        if(r+c+q == 0) break;
        vector<vector<ll>> d(r, vector<ll>(c));
        SegmentTree2D<S, op, e> seg(r, c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> d[i][j];
                seg.set(i, j, d[i][j]);
            }
        }
        seg.build();
        while(q--){
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            cout << seg.query(r1, c1, r2+1, c2+1) << endl;
        }
    }
    return 0;
}
