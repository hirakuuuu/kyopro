#line 2 ".lib/template.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <functional>
#include <cassert>
#include <climits>
#include <iomanip>
#include <numeric>
#include <memory>
#include <random>
#define allof(obj) (obj).begin(), (obj).end()
#define range(i, l, r) for(int i=l;i<r;i++)
#define bit_subset(i, S) for(int i=S, zero_cnt=0;(zero_cnt+=i==S)<2;i=(i-1)&S)
#define bit_kpop(i, n, k) for(int i=(1<<k)-1,x_bit,y_bit;i<(1<<n);x_bit=(i&-i),y_bit=i+x_bit,i=(!i?(1<<n):((i&~y_bit)/x_bit>>1)|y_bit))
#define bit_kth(i, k) ((i >> k)&1)
#define bit_highest(i) (i?63-__builtin_clzll(i):-1)
#define bit_lowest(i) (i?__builtin_ctzll(i):-1)
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
using ul = uint64_t;
using pi = std::pair<int, int>;
using pl = std::pair<ll, ll>;
template<typename T>
using vec = std::vector<T>;
using namespace std;

template<typename F, typename S>
std::ostream &operator<<(std::ostream &dest, const std::pair<F, S> &p){
  dest << p.first << ' ' << p.second;
  return dest;
}
template<typename T>
std::ostream &operator<<(std::ostream &dest, const std::vector<std::vector<T>> &v){
  int sz = v.size();
  if(sz==0) return dest;
  for(int i=0;i<sz;i++){
    int m = v[i].size();
    for(int j=0;j<m;j++) dest << v[i][j] << (i!=sz-1&&j==m-1?'\n':' ');
  }
  return dest;
}
template<typename T>
std::ostream &operator<<(std::ostream &dest, const std::vector<T> &v){
  int sz = v.size();
  if(sz==0) return dest;
  for(int i=0;i<sz-1;i++) dest << v[i] << ' ';
  dest << v[sz-1];
  return dest;
}
template<typename T, size_t sz>
std::ostream &operator<<(std::ostream &dest, const std::array<T, sz> &v){
  if(sz==0) return dest;
  for(int i=0;i<sz-1;i++) dest << v[i] << ' ';
  dest << v[sz-1];
  return dest;
}
template<typename T>
std::ostream &operator<<(std::ostream &dest, const std::set<T> &v){
  for(auto itr=v.begin();itr!=v.end();){
    dest << *itr;
    itr++;
    if(itr!=v.end()) dest << ' ';
  }
  return dest;
}
template<typename T, typename E>
std::ostream &operator<<(std::ostream &dest, const std::map<T, E> &v){
  for(auto itr=v.begin();itr!=v.end();){
    dest << '(' << itr->first << ", " << itr->second << ')';
    itr++;
    if(itr!=v.end()) dest << '\n';
  }
  return dest;
}
template<typename T>
vector<T> make_vec(size_t sz, T val){return std::vector<T>(sz, val);}
template<typename T, typename... Tail>
auto make_vec(size_t sz, Tail ...tail){
  return std::vector<decltype(make_vec<T>(tail...))>(sz, make_vec<T>(tail...));
}
template<typename T>
vector<T> read_vec(size_t sz){
  std::vector<T> v(sz);
  for(int i=0;i<sz;i++) std::cin >> v[i];
  return v;
}
template<typename T, typename... Tail>
auto read_vec(size_t sz, Tail ...tail){
  auto v = std::vector<decltype(read_vec<T>(tail...))>(sz);
  for(int i=0;i<sz;i++) v[i] = read_vec<T>(tail...);
  return v;
}

void io_init(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
}
#line 2 ".lib/monoid.hpp"
#include <limits>
#line 6 ".lib/monoid.hpp"

struct point_min_range_min{
  template<typename T>
  static T id(){
    return std::numeric_limits<T>::max();
  }
  template<typename T>
  static T update(T a, T b){
    return std::min(a, b);
  }
  template<typename T>
  static T merge(T a, T b){
    return std::min(a, b);
  }
};
struct point_mul_range_mul{
  template<typename T>
  static T id(){
    return 1;
  }
  template<typename T>
  static T update(T a, T b){
    return a * b;
  }
  template<typename T>
  static T merge(T a, T b){
    return a * b;
  }
};
struct point_add_range_min{
  template<typename T>
  static T id(){
    return std::numeric_limits<T>::max();
  }
  template<typename T>
  static T update(T a, T b){
    if(a == id<T>()) return b;
    else if(b == id<T>()) return a;
    return a + b;
  }
  template<typename T>
  static T merge(T a, T b){
    return std::min(a, b);
  }
};

struct point_max_range_max{
  template<typename T>
  static T id(){
    return std::numeric_limits<T>::min();
  }
  template<typename T>
  static T update(T a, T b){
    return std::max(a, b);
  }
  template<typename T>
  static T merge(T a, T b){
    return std::max(a, b);
  }
};

struct point_add_range_max{
  template<typename T>
  static T id(){
    return std::numeric_limits<T>::min();
  }
  template<typename T>
  static T update(T a, T b){
    if(a == id<T>()) return b;
    else if(b == id<T>()) return a;
    return a + b;
  }
  template<typename T>
  static T merge(T a, T b){
    return std::max(a, b);
  }
};

struct point_add_range_sum{
  template<typename T>
  static T id(){
    return 0;
  }
  template<typename T>
  static T update(T a, T b){
    return a + b;
  }
  template<typename T>
  static T merge(T a, T b){
    return a + b;
  }
  template<typename T>
  static T flip(T a){
    return a;
  }
};
struct point_set_range_composite{
  static constexpr int mod = 998244353;
  template<typename T>
  static T id(){
    return {1, 0};
  }
  template<typename T>
  static T update(T a, T b){
    return b;
  }
  template<typename T>
  static T merge(T a, T b){
    int xy = ((long long)a.first * b.first) % mod;
    int ab = ((long long)a.second * b.first + b.second) % mod;
    return {xy, ab};
  }
};
struct point_set_range_composite_flip{
  static constexpr int mod = 998244353;
  template<typename T>
  static T id(){
    return {1, 0, 0};
  }
  template<typename T>
  static T update(T a, T b){
    return b;
  }
  template<typename T>
  static T flip(T a){
    return {a[0], a[2], a[1]};
  }
  template<typename T>
  static T merge(T a, T b){
    int xy = ((long long)a[0] * b[0]) % mod;
    int ab = ((long long)a[1] * b[0] + b[1]) % mod;
    int ba = ((long long)b[2] * a[0] + a[2]) % mod;
    return {xy, ab, ba};
  }
};

// 区間set, これまでにsetした物の中ならどれかを取得
struct range_set_get_any{
  template<typename Val>
  static Val id1(){
    return nullptr;
  }
  template<typename Lazy>
  static Lazy id2(){
    return nullptr;
  }
  template<typename Lazy>
  static Lazy propagate(Lazy l, Lazy x){
    return (x == nullptr ? l : x);
  }
  template<typename Val, typename Lazy>
  static Val apply(Val v, Lazy x, int l, int r){
    return (x == nullptr ? v : x);
  }
};

struct range_add_range_sum{
  template<typename T>
  static T id1(){
    return T(0);
  }
  template<typename E>
  static E id2(){
    return E(0);
  }
  template<typename T>
  static T merge(T a, T b){
    return a + b;
  }
  template<typename T, typename E>
  static T apply(T a, E b, int l, int r){
    return a + b * (r - l);
  }
  template<typename E>
  static E propagate(E a, E b){
    return a + b;
  }
  template<typename T>
  static T flip(T a){
    return a;
  }
};

struct range_add_range_max{
  template<typename T>
  static T id1(){
    return std::numeric_limits<T>::min();
  }
  template<typename E>
  static E id2(){
    return 0;
  }
  template<typename T>
  static T merge(T a, T b){
    return std::max(a, b);
  }
  template<typename T, typename E>
  static T apply(T a, E b, int l, int r){
    if(a == id1<T>()) return b * (r - l);
    return a + b;
  }
  template<typename E>
  static E propagate(E a, E b){
    return a + b;
  }
};

/*
#include <array>
struct range_affine_range_sum{
  const static long long MOD = 998244353;
  template<typename T>
  static T id1(){
    return 0;
  }
  template<typename E>
  static E id2(){
    return E{1, 0};
  }
  template<typename T>
  static T merge(T a, T b){
    return (a + b) % MOD;
  }
  template<typename T, typename E>
  static T apply(T a, E b, int l, int r){
    return (a * b[0] + b[1] * (r - l)) % MOD;
  }
  template<typename E>
  static E propagate(E a, E b){
    return E{(a[0] * b[0]) % MOD, (a[1] * b[0] + b[1]) % MOD};
  }
};
*/
struct range_affine_range_sum{
  const static int MOD = 998244353;
  template<typename T>
  static T id1(){
    return 0;
  }
  template<typename E>
  static E id2(){
    return E{1, 0};
  }
  template<typename T>
  static T merge(T a, T b){
    return (a + b) % MOD;
  }
  template<typename T, typename E>
  static T apply(T a, E b, int l, int r){
    return ((long long)a * b.first + (long long)b.second * (r - l)) % MOD;
  }
  template<typename E>
  static E propagate(E a, E b){
    return E{((long long)a.first * b.first) % MOD, ((long long)a.second * b.first + b.second) % MOD};
  }
};

struct range_add_range_min_count{
  static constexpr int INF = std::numeric_limits<int>::max();
  template<typename T>
  static T id1(){
    return {INF, 0};
  }
  template<typename E>
  static E id2(){
    return 0;
  }
  template<typename T>
  static T merge(T a, T b){
    if(a.first != b.first) return a.first < b.first ? a : b;
    return {a.first, a.second + b.second};
  }
  template<typename T, typename E>
  static T apply(T a, E b, int l, int r){
    if(a.first == INF) return {b, r - l};
    return {a.first + b, a.second};
  }
  template<typename E>
  static E propagate(E a, E b){
    return a + b;
  }
};

struct range_composite_lct{
  static constexpr int MOD = 998244353;
  template<typename T>
  // 1x + 0, 1x + 0
  static T id1(){
    return std::array<int, 3>{1, 0, 0};
  }
  // no use
  template<typename E>
  static E id2(){
    return false;
  }
  // b(a(x)), a(b(x))
  template<typename T>
  static T merge(T a, T b){
    int ba1 = ((long long)b[0] * a[0]) % MOD;
    int ba2 = ((long long)b[0] * a[1] + b[1]) % MOD;
    int ab2 = ((long long)a[0] * b[2] + a[2]) % MOD;
    return std::array<int, 3>{ba1, ba2, ab2};
  }
  // no use
  template<typename T, typename E>
  static T apply(T a, E b, int l, int r){
    return a;
  }
  // no use
  template<typename E>
  static E propagate(E a, E b){
    return false;
  }
  //
  template<typename T>
  static T flip(T a){
    return std::array<int, 3>{a[0], a[2], a[1]};
  }
};
#line 6 ".lib/data_structure/segment_tree/dynamic_sequence_merge_split.hpp"

template<typename monoid, typename Val>
struct dynamic_sequence_merge_split{
private:
  struct node{
    node *l, *r;
    int sz;
    bool flip;
    Val val, sum;
    node(Val _val = monoid::template id<Val>()): l(nullptr), r(nullptr), sz(1),
    flip(false), val(_val), sum(_val){}
  };
  node *root;
  int size(node *v){
    return !v ? 0 : v->sz;
  }
  void update(node *v){
    v->sz = 1;
    v->sum = v->val;
    if(v->l){
      v->sz += v->l->sz;
      v->sum = monoid::template merge<Val>(v->l->sum, v->sum);
    }
    if(v->r){
      v->sz += v->r->sz;
      v->sum = monoid::template merge<Val>(v->sum, v->r->sum);
    }
  }
  void push_down(node *v){
    if(!v) return;
    if(v->flip){
      if(v->l) flip(v->l);
      if(v->r) flip(v->r);
      v->flip = false;
    }
  }
  void flip(node *v){
    std::swap(v->l, v->r);
    v->sum = monoid::template flip<Val>(v->sum);
    v->flip ^= 1;
  }
  // vの左の子をvの位置に持ってくる
  node *rotate_right(node *v){
    node *l = v->l;
    v->l = l->r;
    l->r = v;
    update(v);
    update(l);
    return l;
  }
  // vの右の子をvの位置に持ってくる
  node *rotate_left(node *v){
    node *r = v->r;
    v->r = r->l;
    r->l = v;
    update(v);
    update(r);
    return r;
  }
  /*
  // k番目(0 <= k < size)のノードを根にする
  node *splay_top_down(node *v, int k){
    push_down(v);
    int szl = v->l ? v->l->sz : 0;
    if(k == szl) return v;
    if(k < szl){
      v->l = splay_top_down(v->l, k);
      v = rotate_right(v);
    }else{
      v->r = splay_top_down(v->r, k - szl - 1);
      v = rotate_left(v);
    }
    update(v);
    return v;
  }
  */
  node *splay_top_down(node *v, int k, node *u = nullptr){
    push_down(v);
    int szl = v->l ? v->l->sz : 0;
    if(k == szl) return u = v;
    if(k < szl){
      v->l = splay_top_down(v->l, k);
      update(v);
      if(v->l == u) return v;
      if(v->l->l == u) v = rotate_right(v);
      else v->l = rotate_left(v->l);
      return rotate_right(v);
    }else{
      v->r = splay_top_down(v->r, k - szl - 1);
      update(v);
      if(v->r == u) return v;
      if(v->r->r == u) v = rotate_left(v);
      else v->r = rotate_right(v->r);
      return rotate_left(v);
    }
    return v;
  }
  node *merge(node *l, node *r){
    if(!l || !r) return !l ? r : l;
    r = splay_top_down(r, 0);
    r->l = l;
    update(r);
    return r;
  }
  // 左がkノードになるように分割
  std::pair<node*, node*> split(node *v, int k){
    int n = size(v);
    if(k >= n) return {v, nullptr};
    v = splay_top_down(v, k);
    node *l = v->l;
    v->l = nullptr;
    update(v);
    return {l, v};
  }
  std::tuple<node*, node*, node*> split3(node *v, int l, int r){
    if(l == 0){
      auto [b, c] = split(v, r);
      return {nullptr, b, c};
    }
    v = splay_top_down(v, l - 1); //    (l - 1個)  /  v  / (残り)
    auto [b, c] = split(v->r, r - l); // cがnullptrまたはcの左が空
    v->r = nullptr; // vの右が空
    update(v);
    return {v, b, c};
  }
  // split3によって分割された組でないと壊れる
  node *merge3(node *a, node *b, node *c){
    node *v = merge(b, c); // O(1)
    if(!a) return v;
    a->r = v; // O(1)
    update(a);
    return a;
  }
  node *set_inner(node *v, int k, Val x){
    v = splay_top_down(v, k);
    v->val = x;
    update(v);
    return v;
  }
  node *get_inner(node *v, int k, Val &x){
    v = splay_top_down(v, k);
    x = v->val;
    return v;
  }
  node *update_inner(node *v, int k, Val x){
    v = splay_top_down(v, k);
    v->val = monoid::template update<Val>(v->val, x);
    update(v);
    return v;
  }
  node *query_inner(node *v, int l, int r, Val &res){
    if(r == l) return v;
    auto [a, b, c] = split3(v, l, r);
    res = b->sum;
    return merge3(a, b, c);
  }
  node *flip_inner(node *v, int l, int r){
    if(r == l) return v;
    auto [a, b, c] = split3(v, l, r);
    if(b) flip(b);
    return merge3(a, b, c);
  }
  node *insert_inner(node *v, int k, node *u){
    if(k == size(v)){
      u->l = v;
      update(u);
      return u;
    }
    if(k == 0){
      u->r = v;
      update(u);
      return u;
    }
    v = splay_top_down(v, k);
    u->l = v->l;
    v->l = u;
    update(u);
    update(v);
    return v;
  }
  node *erase_inner(node *v, int k){
    v = splay_top_down(v, k);
    return merge(v->l, v->r);
  }
  node *build(const std::vector<Val> &v, int l, int r){
    int m = (l + r) >> 1;
    node *u = new node(v[m]);
    if(m > l) u->l = build(v, l, m);
    if(r > m + 1) u->r = build(v, m + 1, r);
    update(u);
    return u;
  }
  /*
  template<typename F>
  node *bisect_from_left(node *v, F &f, int l, Val &ok, int &idx){
    if(!v || v->sz <= l) return -1;
    int szl = v->l ? v->l->sz : 0, szm = szl + 1;
    Val m = monoid::template merge<Val>(ok, v->sum);
    if(!l && !f(m)){
      ok = m;
      return -1;
    }
    v->l = bisect_from_left(v->l, f, l, ok, idx);
    if(x != -1) return x;
    if(l <= szl){
      ok = monoid::template merge<Val>(ok, v->val);
      if(f(ok)) return szl;
    }
    int res = bisect_from_left(v->r, f, std::max(l - szm, 0), ok);
    return res == -1 ? res : res + szm;
  }
  */
  /*
  template<typename F>
  int bisect_from_right(node *v, F &f, int r, Val &ok){
    if(!v || r < 0) return -1;
    int szl = v->l ? v->l->sz : 0, szm = szl + 1;
    Val m = monoid::template merge<Val>(ok, v->sum);
    if(v->sz <= r && !f(m)){
      ok = m;
      return -1;
    }
    int x = bisect_from_right(v->r, f, r - szm, ok);
    if(x != -1) return x + szm;
    if(szl <= r){
      ok = monoid::template merge<Val>(ok, v->val);
      if(f(ok)) return szl;
    }
    return bisect_from_right(v->l, f, r, ok);
  }
  */
  dynamic_sequence_merge_split(node *r): root(r){}
public:
  dynamic_sequence_merge_split(): root(nullptr){}
  dynamic_sequence_merge_split(const std::vector<Val> &v): root(nullptr){
    if(!v.empty()) root = build(v, 0, v.size());
  }
  int size(){return size(root);}
  void set(int k, Val x){
    assert(0 <= k && k < size());
    root = set_inner(root, k, x);
  }
  Val get(int k){
    assert(0 <= k && k < size());
    Val res = monoid::template id<Val>();
    root = get_inner(root, k, res);
    return res;
  }
  void update(int l, int r, Val x){
    assert(0 <= l && r <= size());
    root = update_inner(root, l, r, x);
  }
  Val query(int l, int r){
    assert(0 <= l && r <= size());
    Val res = monoid::template id<Val>();
    root = query_inner(root, l, r, res);
    return res;
  }
  void flip(int l, int r){
    assert(0 <= l && r <= size());
    root = flip_inner(root, l, r);
  }
  void insert(int k, Val x){
    assert(0 <= k && k <= size());
    root = insert_inner(root, k, new node(x));
  }
  void erase(int k){
    assert(0 <= k && k < size());
    root = erase_inner(root, k);
  }
};

template<typename monoid, typename Val, typename Lazy>
struct lazy_dynamic_sequence_merge_split{
private:
  struct node{
    node *l, *r;
    int sz;
    bool flip;
    Val val, sum;
    Lazy lazy;
    node(Val _val = monoid::template id1<Val>()): l(nullptr), r(nullptr), sz(1),
    flip(false), val(_val), sum(_val), lazy(monoid::template id2<Lazy>()){}
  };
  node *root;
  int size(node *v){
    return !v ? 0 : v->sz;
  }
  void update(node *v){
    v->sz = 1;
    v->sum = v->val;
    if(v->l){
      v->sz += v->l->sz;
      v->sum = monoid::template merge<Val>(v->l->sum, v->sum);
    }
    if(v->r){
      v->sz += v->r->sz;
      v->sum = monoid::template merge<Val>(v->sum, v->r->sum);
    }
  }
  void push_down(node *v){
    if(!v) return;
    if(v->lazy != monoid::template id2<Lazy>()){
      if(v->l) propagate(v->l, v->lazy);
      if(v->r) propagate(v->r, v->lazy);
      v->lazy = monoid::template id2<Lazy>();
    }
    if(v->flip){
      if(v->l) flip(v->l);
      if(v->r) flip(v->r);
      v->flip = false;
    }
  }
  void propagate(node *v, Lazy x){
    v->lazy = monoid::template propagate<Lazy>(v->lazy, x);
    v->val = monoid::template apply<Val, Lazy>(v->val, x, 0, 1);
    v->sum = monoid::template apply<Val, Lazy>(v->sum, x, 0, v->sz);
  }
  void flip(node *v){
    std::swap(v->l, v->r);
    v->sum = monoid::template flip<Val>(v->sum);
    v->flip ^= 1;
  }
  // vの左の子をvの位置に持ってくる
  node *rotate_right(node *v){
    node *l = v->l;
    v->l = l->r;
    l->r = v;
    update(v);
    update(l);
    return l;
  }
  // vの右の子をvの位置に持ってくる
  node *rotate_left(node *v){
    node *r = v->r;
    v->r = r->l;
    r->l = v;
    update(v);
    update(r);
    return r;
  }
  // k番目(0 <= k < size)のノードを根にする
  node *splay_top_down(node *v, int k){
    push_down(v);
    int szl = v->l ? v->l->sz : 0;
    if(k == szl) return v;
    if(k < szl){
      v->l = splay_top_down(v->l, k);
      v = rotate_right(v);
    }else{
      v->r = splay_top_down(v->r, k - szl - 1);
      v = rotate_left(v);
    }
    update(v);
    return v;
  }
  node *merge(node *l, node *r){
    if(!l || !r) return !l ? r : l;
    r = splay_top_down(r, 0);
    r->l = l;
    update(r);
    return r;
  }
  // 左がkノードになるように分割
  std::pair<node*, node*> split(node *v, int k){
    int n = size(v);
    if(k >= n) return {v, nullptr};
    v = splay_top_down(v, k);
    node *l = v->l;
    v->l = nullptr;
    update(v);
    return {l, v};
  }
  std::tuple<node*, node*, node*> split3(node *v, int l, int r){
    if(l == 0){
      auto [b, c] = split(v, r);
      return {nullptr, b, c};
    }
    v = splay_top_down(v, l - 1); //    (l - 1個)  /  v  / (残り)
    auto [b, c] = split(v->r, r - l); // cがnullptrまたはcの左が空
    v->r = nullptr; // vの右が空
    update(v);
    return {v, b, c};
  }
  // split3によって分割された組でないと壊れる
  node *merge3(node *a, node *b, node *c){
    node *v = merge(b, c); // O(1)
    if(!a) return v;
    a->r = v; // O(1)
    update(a);
    return a;
  }
  node *set_inner(node *v, int k, Val x){
    v = splay_top_down(v, k);
    v->val = x;
    update(v);
    return v;
  }
  node *get_inner(node *v, int k, Val &x){
    v = splay_top_down(v, k);
    x = v->val;
    return v;
  }
  node *update_inner(node *v, int l, int r, Lazy x){
    if(r == l) return v;
    auto [a, b, c] = split3(v, l, r);
    propagate(b, x);
    return merge3(a, b, c);
  }
  node *query_inner(node *v, int l, int r, Val &res){
    if(r == l) return v;
    auto [a, b, c] = split3(v, l, r);
    res = b->sum;
    return merge3(a, b, c);
  }
  node *flip_inner(node *v, int l, int r){
    if(r == l) return v;
    auto [a, b, c] = split3(v, l, r);
    if(b) flip(b);
    return merge3(a, b, c);
  }
  node *insert_inner(node *v, int k, node *u){
    if(k == size(v)){
      u->l = v;
      update(u);
      return u;
    }
    if(k == 0){
      u->r = v;
      update(u);
      return u;
    }
    v = splay_top_down(v, k);
    u->l = v->l;
    v->l = u;
    update(u);
    update(v);
    return v;
  }
  node *erase_inner(node *v, int k){
    v = splay_top_down(v, k);
    return merge(v->l, v->r);
  }
  node *build(const std::vector<Val> &v, int l, int r){
    int m = (l + r) >> 1;
    node *u = new node(v[m]);
    if(m > l) u->l = build(v, l, m);
    if(r > m + 1) u->r = build(v, m + 1, r);
    update(u);
    return u;
  }
  lazy_dynamic_sequence_merge_split(node *r): root(r){}
public:
  lazy_dynamic_sequence_merge_split(): root(nullptr){}
  lazy_dynamic_sequence_merge_split(const std::vector<Val> &v): root(nullptr){
    if(!v.empty()) root = build(v, 0, v.size());
  }
  int size(){return size(root);}
  void set(int k, Val x){
    assert(0 <= k && k < size());
    root = set_inner(root, k, x);
  }
  Val get(int k){
    assert(0 <= k && k < size());
    Val res = monoid::template id1<Val>();
    root = get_inner(root, k, res);
    return res;
  }
  void update(int l, int r, Lazy x){
    assert(0 <= l && r <= size());
    root = update_inner(root, l, r, x);
  }
  Val query(int l, int r){
    assert(0 <= l && r <= size());
    Val res = monoid::template id1<Val>();
    root = query_inner(root, l, r, res);
    return res;
  }
  void flip(int l, int r){
    assert(0 <= l && r <= size());
    root = flip_inner(root, l, r);
  }
  void insert(int k, Val x){
    assert(0 <= k && k <= size());
    root = insert_inner(root, k, new node(x));
  }
  void erase(int k){
    assert(0 <= k && k < size());
    root = erase_inner(root, k);
  }
};
#line 3 "a.cpp"

struct range_affine_range_sum2{
  static constexpr int MOD = 998244353;
  template<typename T>
  static constexpr T id1(){
    return T(0);
  }
  template<typename E>
  static constexpr E id2(){
    return {1, 0};
  }
  template<typename T>
  static constexpr T merge(T a, T b){
    return (a + b >= MOD ? a + b - MOD : a + b);
  }
  template<typename T, typename E>
  static constexpr T apply(T a, E b, int l, int r){
    return ((long long)a * b.first + (long long)b.second * (r - l)) % MOD;
  }
  template<typename E>
  static constexpr E propagate(E a, E b){
    return {((long long)a.first * b.first) % MOD, ((long long)a.second * b.first + b.second) % MOD};
  }
  template<typename T>
  static constexpr T flip(T a){
    return a;
  }
};

#line 2 ".lib/fast_io.hpp"
#include <unistd.h>

struct IO {
  static const int bufsize=1<<25;
  char ibuf[bufsize], obuf[bufsize];
  char *ip, *op;
  IO(): ip(ibuf), op(obuf) { for(int t = 0, k = 0; (k = read(STDIN_FILENO, ibuf+t, sizeof(ibuf)-t)) > 0; t+=k); }
  ~IO(){ for(int t = 0, k = 0; (k = write(STDOUT_FILENO, obuf+t, op-obuf-t)) > 0; t+=k); }

  long long in(){
    long long x=0;
    bool neg=false;
    for(;*ip<'+';ip++) ;
    if(*ip=='-'){ neg=true; ip++;}
    else if(*ip=='+') ip++;
    for(;*ip>='0';ip++) x = 10*x+*ip-'0';
    if(neg) x = -x;
    return x;
  }
  char in_char(){
    for(; *ip < '!'; ip++) ;
    return *ip++;
  }
  void out(long long x, char c=0){
    static char tmp[20];
    if(x==0) *op++ = '0';
    else {
      int i;
      if(x<0){
        *op++ = '-';
        x = -x;
      }
      for(i=0; x; i++){
        tmp[i] = x % 10;
        x /= 10;
      }
      for(i--; i>=0; i--) *op++ = tmp[i]+'0';
    }
    if(c) *op++ = c;
  }
  void out_char(char x, char c=0){
    *op++ = x;
    if(c) *op++ = c;
  }
} io;

template<typename T>
void read(T &x){
  x = io.in();
}
char get_char(){
  return io.in_char();
}
void print(long long x, char c = '\0'){
  io.out(x, c);
}
void print_char(char x, char c = '\0'){
  io.out_char(x, c);
}
#line 33 "a.cpp"

int main(){
    string s; cin >> s; 
    // かっこ列だけ考えて大文字小文字をそろえる
    int acc = 0;
    reverse(s.begin(), s.end());
    for(auto &ss: s){
        if(ss == '('){
            acc--;
        }else if(ss == ')'){
            acc++;
        }else{
            if(acc%2){
                if(islower(ss)) ss = toupper(ss);
                else ss = tolower(ss);
            }
        }
    }
    reverse(s.begin(), s.end());
    vector<int> s_;
    for(auto ss: s) s_.push_back((int)ss);
    lazy_dynamic_sequence_merge_split<range_affine_range_sum2, int, std::pair<int, int>> seg(s_);
    vector<pair<int, int>> op;
    stack<int> l;
    rep(i, 0, s.size()){
        if(s[i] == '('){
            l.push(i);
        }else if(s[i] == ')'){
            int L = l.top(); l.pop();
            op.push_back({L, i});
        }
    }
    for(auto [l, r]: op){
        cout << l << ' ' << r << endl;
        seg.flip(l, r+1);
    }
    
    rep(i, 0, s.size()){
        cout << seg.get(i) << endl;
        if(seg.get(i) != (int)'(' && seg.get(i) != (int)')') cout << (char)seg.get(i);
    }
    cout << endl;
}
