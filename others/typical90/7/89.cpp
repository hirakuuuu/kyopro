#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
// constexpr ll MOD = 998244353;
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


// 座標圧縮
ll comp(vector<ll>&a){
  set<ll>s(a.begin(),a.end());
  map<ll,ll>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
  return cnt;
}

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll mx = comp(a);
    FenwickTree<ll> bit(mx);
    vector<ll> dp(n);
    int r = 0;
    ll t = 0;
    rep(l, 0, n){
        while(r < n && t <= k){
            bit.add(a[r], 1);
            t += bit.sum(a[r]+1, mx);
            if(t > k){
                bit.add(a[r], -1);
                t -= bit.sum(a[r]+1, mx); 
                break;
            }
            r++;
        }
        dp[l] = r;
        bit.add(a[l], -1);
        t -= bit.sum(0, a[l]);
    }

    // いもす
    vector<ll> dp2(n+2), acc(n+1);
    dp2[0] = 1;
    dp2[dp[0]] = -1;
    rep(i, 1, n){
        {
            dp2[i] += dp2[i-1];
            dp2[i] %= MOD;
            dp2[dp[i]] -= dp2[i-1];
            dp2[dp[i]] %= MOD;
        }
        dp2[i] += dp2[i-1];
        dp2[i] %= MOD;
        if(dp2[i] < 0) dp2[i] += MOD;
    }
    cout << dp2[n-1] << endl;





    
    return 0;
}