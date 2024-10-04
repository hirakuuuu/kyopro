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


int main(){
    int n; cin >> n;
    vector<int> rev_w(n+1), rev_b(n+1);
    rep(i, 0, 2*n){
        char c; cin >> c;
        int a; cin >> a;
        if(c == 'W') rev_w[a] = i;
        else rev_b[a] = i;
    }

    vector<vector<int>> gw(n+1, vector<int>(2*n));
    vector<vector<int>> gb(n+1, vector<int>(2*n));
    FenwickTree<int> bit_w(2*n);
    FenwickTree<int> bit_b(2*n);
    rep(i, 1, n+1){
        bit_w.add(rev_w[i], 1);
        bit_b.add(rev_b[i], 1);
        rep(j, 0, 2*n){
            gw[i][j] = bit_w.sum(j, 2*n);
            gb[i][j] = bit_b.sum(j, 2*n);
        }
    }


    vector<vector<int>> dp(n+1, vector<int>(n+1, IINF));
    dp[0][0] = 0;
    rep(i, 0, n+1){
        rep(j, 0, n+1){
            if(i < n){
                int cost = (rev_w[i+1]+gw[i][rev_w[i+1]]+gb[j][rev_w[i+1]])-(i+j);
                chmin(dp[i+1][j], dp[i][j]+cost);
            }
            if(j < n){
                int cost = (rev_b[j+1]+gw[i][rev_b[j+1]]+gb[j][rev_b[j+1]])-(i+j);
                chmin(dp[i][j+1], dp[i][j]+cost);
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}