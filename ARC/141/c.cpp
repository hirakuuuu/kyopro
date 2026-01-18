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
- p が辞書順最小であるために
- p[i] > p[j] なる i, j の位置を入れ替えると正しいかっこ列とならないようにしたい．
    - i < j \land p[i] > p[j] \Rightarrow s[p[i]] = '(' \land s[p[j]] = ')'
- (, ) それぞれで添え字を抜き出したときにソートされていないといけない．
- p[i] > p[i+1] > p[i+2] なる i があるとだめ
p[i] > p[i+1] なる i について，s[p[i]] = (, s[p[i+1]] = ) が確定
- q[i] < q[i+1] < q[i+2] なる i があるとだめ


1 2 4 3

1 2 3 4

3 4 2 1



*/

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
    vector<int> p(2*n), q(2*n);
    rep(i, 0, 2*n) cin >> p[i], p[i]--;
    rep(i, 0, 2*n) cin >> q[i], q[i]--;

    string s(2*n, '?');
    if(p[0] == q[2*n-1] || p[2*n-1] == q[0]){
        cout << -1 << endl;
        return 0;
    }
    s[p[0]] = s[q[0]] = '(';
    s[p[2*n-1]] = s[q[2*n-1]] = ')';

    {
        FenwickTree<int> lbit(2*n);
        FenwickTree<int> rbit(2*n);
        rep(i, 0, 2*n) rbit.add(i, 1);
        rep(i, 0, 2*n){
            lbit.add(p[i], 1);
            rbit.add(p[i], -1);
            int lcnt = lbit.sum(p[i]+1, 2*n), rcnt = rbit.sum(0, p[i]);
            if(lcnt && rcnt){
                cout << -1 << endl;
                return 0;
            }else if(lcnt){
                if(s[p[i]] == '('){
                    cout << -1 << endl;
                    return 0;
                }
                s[p[i]] = ')';
            }else if(rcnt){
                if(s[p[i]] == ')'){
                    cout << -1 << endl;
                    return 0;
                }
                s[p[i]] = '(';
            }
        }
    }
    {
        FenwickTree<int> lbit(2*n);
        FenwickTree<int> rbit(2*n);
        rep(i, 0, 2*n) rbit.add(i, 1);
        rep(i, 0, 2*n){
            lbit.add(q[i], 1);
            rbit.add(q[i], -1);
            int lcnt = lbit.sum(0, q[i]), rcnt = rbit.sum(q[i]+1, 2*n);
            if(lcnt && rcnt){
                cout << -1 << endl;
                return 0;
            }else if(lcnt){
                if(s[q[i]] == '('){
                    cout << -1 << endl;
                    return 0;
                }
                s[q[i]] = ')';
            }else if(rcnt){
                if(s[q[i]] == ')'){
                    cout << -1 << endl;
                    return 0;
                }
                s[q[i]] = '(';
            }
        }
    }

    int cnt0 = 0, cnt1 = 0;
    rep(i, 0, 2*n){
        if(s[i] == '(') cnt0++;
        if(s[i] == ')') cnt1++;
    }
    if(cnt0 > n || cnt1 > n){
        cout << -1 << endl;
    }
    cout << s << endl;
   
    return 0;
}