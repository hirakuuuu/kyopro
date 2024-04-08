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


int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> q(n+1);
    rep(i, 0, m){
        int l, r, x; cin >> l >> r >> x;
        l--;
        q[r].push_back({l, x});
    }
    rep(i, 1, n+1){
        sort(q[i].begin(), q[i].end());
    }

    FenwickTree<int> ft(n);
    priority_queue<int> que;
    rep(r, 1, n+1){
        que.push(r-1);
        for(auto lx: q[r]){
            auto [l, x] = lx;
            int tmp = ft.sum(l, r);
            if(tmp >= x) continue;
            rep(i, 0, x-tmp){
                int p = que.top(); que.pop();
                ft.set(p, 1);
            }
        }
    }

    rep(i, 0, n){
        cout << ft.sum(i, i+1) << ' ';
    }
    cout << endl;



    
    return 0;
}