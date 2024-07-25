#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
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

/*
添え字を適当に選んだときに、x_i, x_{i+1} の２つの間に A[x_i], A[x_{i+1}] と同じ数字があってはならない
逆にこれを満たす選び方は、同じ数列を選ぶときに添え字の選び方が一意に定まる
（前からの貪欲（辞書順最初）と後ろからの貪欲（辞書順最後）で選び方が一致するので）

これは各添え字を最後に持つような選び方を BIT に載せることで実現できる
- それが始めて現れるならそれのみの列の分（１）を足す
- そうでなければ, その前に現れたその数字の分と、その後の数字の分からは遷移ができる
*/

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }


    FenwickTree<mint> bit(n+1);
    vector<int> pre(n, -1);
    vector<mint> dp(n);
    rep(i, 0, n){
        mint tot = bit.sum(max(0, pre[a[i]]), n+1);
        if(pre[a[i]] == -1) tot += 1; 
        dp[i] = tot;
        if(pre[a[i]] != -1) bit.add(pre[a[i]], -dp[pre[a[i]]]);
        pre[a[i]] = i;
        bit.add(i, dp[i]);
    }
    cout << bit.sum(0, n+1).val() << endl;


    
    return 0;
}