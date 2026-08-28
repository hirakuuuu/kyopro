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
mo は2次元平面上のハミルトンサイクルを求めるうえで O(N\sqrt(Q)) を達成できるというイメージを持とう
mo's のたどり方が最悪ケースではほぼ最適なので，今回のケースだと
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
    vector<int> build() {
        int q = (int) lr.size();
        int bs = n / min<int>(n, sqrt(q));
        vector< int > ord(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
        int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
        if(ablock != bblock) return ablock < bblock;
        return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
        });
        return ord;
    }

    template< typename A, typename E, typename O >
    void build(const A &add, const E &erase, const O &out) {
        build(add, add, erase, erase, out);
    }
};

int main(){

    int n; cin >> n;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    Mo dat(20000000);
    rep(i, 0, n){
        dat.add(x[i], y[i]);
    }
    vector<int> ord = dat.build();
    rep(i, 0, n){
        if(ord[i] == 0){
            rep(j, 0, n){
                cout << ord[(i+j)%n]+1 << ' ';
            }
            cout << endl;
            break;
        }
    }
    return 0;
}