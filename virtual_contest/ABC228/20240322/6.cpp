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

template <typename F>
struct SegmentTree2D {
 private:
  int id(int h, int w) const { return h * 2 * W + w; }

 public:
  int H, W;
  vector<ll> seg;
  const F f;
  const ll I;

  SegmentTree2D(int h, int w, F _f, const ll& i) : f(_f), I(i) { init(h, w); }

  void init(int h, int w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, I);
  }

  // build にのみ呼ぶ
  void set(int h, int w, const ll& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  ll get(int h, int w) const { return seg[id(h + H, w + W)]; }
  ll operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

  void update(int h, int w, const ll& x) {
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

  ll _inner_query(int h, int w1, int w2) {
    ll res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  ll query(int h1, int w1, int h2, int w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    ll res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

int main(){
    int H, W; cin >> H >> W;
    int h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
    chmin(h2, h1);
    chmin(w2, w1);
    SegmentTree2D seg(H, W, [](ll a, ll b) { return max(a, b); }, 0LL);
    vector<vector<ll>> a(H+1, vector<ll>(W+1));
    rep(i, 1, H+1){
        rep(j, 1, W+1){
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> acc(H+1, vector<ll>(W+1));
    rep(i, 1, H+1){
        rep(j, 1, W+1){
            acc[i][j] = a[i][j]+acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
        }
    }
    rep(i, 0, H-h2+1){
        rep(j, 0, W-w2+1){
            ll tmp = acc[i+h2][j+w2]-acc[i][j+w2]-acc[i+h2][j]+acc[i][j];
            seg.set(i, j, tmp);
        }
    }
    seg.build();
    ll ans = 0LL;
    rep(i, 0, H-h1+1){
        rep(j, 0, W-w1+1){
            ll score = acc[i+h1][j+w1]-acc[i][j+w1]-acc[i+h1][j]+acc[i][j];
            score -= seg.query(i, j, i+h1-h2+1, j+w1-w2+1);
            chmax(ans, score);
        }
    }
    cout << ans << endl;


    return 0;
}