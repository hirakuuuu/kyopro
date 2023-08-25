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
// https://atcoder.jp/contests/abc306/tasks/abc306_f

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

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while(p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

};


int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    map<ll, pair<ll, ll>> id;
    vector<ll> b;
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
        sort(a[i].begin(), a[i].end());
        rep(j, 0, m){
            id[a[i][j]] = {i, j};
        }
    }
    sort(b.begin(), b.end());

    ll ans = 0;
    vector<int> c(n);
    FenwickTree<int> ft(n);
    rep(k, 0, n*m){
        ll tmp = b[k];
        const auto [i, j] = id[tmp];
        ans += (j+1)*(n-i-1)+(ft.sum(i+1, n));
        ft.add(i, 1);
    }
    cout << ans << endl;



    
    return 0;
}