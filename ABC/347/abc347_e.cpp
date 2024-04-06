#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
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
    int n, q; cin >> n >> q;
    vector<int> x(q+1);
    vector<vector<int>> rag(n);
    set<int> s;
    FenwickTree<ll> ft(q+1);
    rep(i, 1, q+1){
        cin >> x[i];
        x[i]--;
        if(s.find(x[i]) != s.end()){
            s.erase(x[i]);
            rag[x[i]].push_back(i);
        }else{
            s.insert(x[i]);
            rag[x[i]].push_back(i);
        }
        ft.add(i, (ll)s.size());
    }
    rep(i, 0, n) rag[i].push_back(q+1);

    rep(i, 0, n){
        ll sum = 0;
        for(int j = 0; j < rag[i].size()-1; j += 2){
            sum += ft.sum(rag[i][j], rag[i][j+1]);
        }
        cout << sum << ' ';
    }
    cout << endl;
    
    return 0;
}