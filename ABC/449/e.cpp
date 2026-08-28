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
    vector<int> a(n);
    vector<int> cnt(m);
    rep(i, 0, n){
        cin >> a[i]; a[i]--;
        cnt[a[i]]++;
    }
    vector<int> s(m);
    iota(s.begin(), s.end(), 0);
    sort(s.begin(), s.end(), [&](int i, int j){
        return cnt[i] < cnt[j];
    });

    vector<pair<ll, ll>> vec;
    for(int l = 0; l < m-1; l++){
        if(cnt[s[l]] == cnt[s[l+1]]) continue;
        vec.push_back({l+1, cnt[s[l+1]]-cnt[s[l]]});
    }



    int k = vec.size();
    vector<ll> acc(k+1);
    acc[0] = 0;
    rep(i, 1, k+1){
        acc[i] = acc[i-1]+vec[i-1].first*vec[i-1].second;
    }

    int q; cin >> q;
    vector<pair<ll, ll>> query(q);
    rep(i, 0, q){
        ll x; cin >> x; x--;
        query[i] = {x, i};
    }
    sort(query.begin(), query.end());

    vector<int> ans(q);
    int r = 0;
    FenwickTree<ll> bit(m);
    rep(i, 0, q){
        auto [x, id] = query[i];
        if(x < n){
            ans[id] = a[x]+1;
        }else{
            while(r < k && acc[r]+n <= x){
                if(r == 0){
                    rep(l, 0, vec[r].first){
                        bit.add(s[l], 1);
                    }
                }else{
                    rep(l, vec[r-1].first, vec[r].first){
                        bit.add(s[l], 1);
                    }
                }
                r++;
            }
            // cout << r << endl;
            if(r == k && x >= acc[k]+n){
                ans[id] = (x-(acc[k]+n))%m+1;
            }else{
                // rep(j, 0, m){
                //     cout << bit.sum(j, j+1) << ' ';
                // }
                // cout << endl;
                ll cnt = (x-n-acc[r-1])%bit.sum(0, m)+1;
                // cout << cnt << endl;
                ll ok = m, ng = 0;
                while(ok-ng > 1){
                    ll mid = (ok+ng)/2;
                    if(bit.sum(0, mid) >= cnt) ok = mid;
                    else ng = mid;
                }
                ans[id] = ok;
            }
        }
    }

    rep(i, 0, q){
        cout << ans[i] << endl;
    }
    
    return 0;
}