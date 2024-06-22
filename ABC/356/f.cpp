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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template <class T>
class FenwickTree {

private:
    int _n;
    vector<T> data;

    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    
public:
    FenwickTree() : _n(0) {}
    explicit FenwickTree(int n) : _n(n), data(n) {}

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        T tmp = sum(p+1)-sum(p);
        add(p, x-tmp);
    }

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while(p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    // [l, r)
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

};

// 座標圧縮
void comp(vector<ll>&a){
  set<ll>s(a.begin(),a.end());
  map<ll,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}

/*
番兵を入れると、setが空とかは気にしなくてよくなる
*/

int main(){
    int q; cin >> q;
    ll k; cin >> k;
    vector<int> T(q);
    vector<ll> X(q);
    rep(i, 0, q) cin >> T[i] >> X[i];
    vector<ll> xx = X;
    // 番兵を追加しておく
    xx.push_back(-k-1);
    xx.push_back((ll)1e18+k+1);
    // 座標圧縮
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());


    set<int> s;
    s.insert(0); s.insert(xx.size()-1);
    set<pair<ll, ll>> ks;
    ks.insert({0LL, xx.size()-1});
    FenwickTree<ll> bit(xx.size());

    rep(i, 0, q){
        int x = lower_bound(xx.begin(), xx.end(), X[i])-xx.begin();

        if(T[i] == 1){
            if(s.find(x) != s.end()){
                bit.add(x, -1);
                s.erase(x);
                auto itr = s.upper_bound(x); // 削除された要素の次の iterator 
                assert(itr != s.begin());
                assert(itr != s.end());
                int r = *itr;
                int l = *prev(itr);
                if(xx[r]-xx[x] > k) ks.erase({x, r});
                if(xx[x]-xx[l] > k) ks.erase({l, x});
                if(xx[r]-xx[l] > k) ks.insert({l, r});
            }else{
                bit.add(x, 1);
                auto itr = s.upper_bound(x); // 削除された要素の次の iterator 
                assert(itr != s.begin());
                assert(itr != s.end());
                int r = *itr;
                int l = *prev(itr);
                if(xx[r]-xx[x] > k) ks.insert({x, r});
                if(xx[x]-xx[l] > k) ks.insert({l, x});
                if(xx[r]-xx[l] > k) ks.erase({l, r});
                s.insert(x);
            }
        }else{
            auto r = ks.lower_bound({x, 0LL});
            assert(r != ks.begin());
            auto l = prev(r);
            cout << bit.sum(l->second, r->first+1) << endl;
        }
    }
    
    return 0;
}