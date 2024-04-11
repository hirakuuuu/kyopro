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

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

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
線分iを1つ固定すると、それと交わらない線分ｊは、l[i] < l[j] を満たすとき、
- r[j] < r[i]
- r[i] < l[j]
のどちらかを満たす。
よって、各l, r の個数をBITにのせ、lの小さい方から更新していけば求まる。
*/

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> lr(m);
    rep(i, 0, m){
         cin >> lr[i].first >> lr[i].second;
         lr[i].first--, lr[i].second--;
    }
    sort(lr.begin(), lr.end());
    vector<vector<int>> r(n);
    rep(i, 0, m){
        r[lr[i].first].push_back(lr[i].second);
    }
    FenwickTree<ll> ft_l(n), ft_r(n);
    rep(i, 0, m){
        ft_l.add(lr[i].first, 1);
        ft_r.add(lr[i].second, 1);
    }
    ll ans = 0, total = m;
    rep(i, 0, n){
        // l = i の線分を削除
        total -= r[i].size();
        ft_l.set(i, 0);
        for(auto rr: r[i]) ft_r.add(rr, -1);

        // 端点以外で交わらない線分を数える
        for(auto rr: r[i]){
            ll cnt = 0;
            cnt += ft_r.sum(i+1, rr+1);
            cnt += ft_l.sum(rr, n);
            ans += (total-cnt);
        }
    }

    cout << ans << endl;

    
    return 0;
}