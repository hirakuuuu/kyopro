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
    string s; cin >> s;
    int n = (int)s.size();
    vector<vector<int>> p(26);
    rep(i, 0, n){
        p[s[i]-'a'].push_back(i);
    }
    // 奇数個の文字が2種以上あると不可能
    int odd = 0;
    rep(i, 0, 26){
        odd += (int)p[i].size()%2;
    }
    if(odd >= 2){
        cout << -1 << endl;
        return 0;
    }

    // そうでない場合、可能
    vector<int> num(n);
    rep(i, 0, 26){
        int m = (int)p[i].size();
        rep(j, 0, m/2){
            num[p[i][j]] = 1;
            num[p[i][m-1-j]] = 2;
        }
    }

    ll ans = 0;
    FenwickTree<ll> bit(n);
    // 前半に置かなければならない文字列の移動コスト
    rep(i, 0, n){
        if(num[i] == 1){
            ans += bit.sum(0, i);
        }else{
            bit.add(i, 1);
        }
    }
    // 後半に置かなければならない文字列の移動コスト
    FenwickTree<ll> bit_(n);
    rrep(i, n-1, 0){
        if(num[i] == 2){
            ans += bit_.sum(i, n);
        }else{
            bit_.add(i, 1);
        }
    }
    // 奇数の場合は真ん中の文字の分をもう１回足す
    rep(i, 0, n){
        if(num[i] == 0){
            ans += bit.sum(0, i) + bit_.sum(i+1, n);
            break;
        }
    }
    ans /= 2; // ２回足しているので、２で割る
    // cout << ans << endl;
    // 前半、後半の転倒数
    vector<pair<int, int>> q;
    rep(i, 0, 26){
        int m = (int)p[i].size();
        rep(j, 0, m/2){
            q.push_back({p[i][j], n-1-p[i][m-1-j]});
        }
    }
    sort(q.begin(), q.end());
    FenwickTree<ll> bit__(n);
    for(auto [_, r]: q){
        ans += bit__.sum(r, n);
        bit__.add(r, 1);
        // cout << r << ' ' << ans << endl;
    }
    cout << ans << endl;

    return 0;
}