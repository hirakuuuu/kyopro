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

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<mint> b(n);
    rep(i, 0, n) b[i] = a[i];
    mint ans = 0;
    rep(i, 0, n){
        ans += b[i]*i;
    }
    vector<int> c(n), cnt(11);
    vector<mint> ten(11);
    ten[1] = 10;
    rep(i, 2, 11) ten[i] = ten[i-1]*10;
    rep(i, 0, n){
        ll a_ = a[i];
        int o = 0;
        while(a_){
            o++;
            a_ /= 10;
        }
        c[i] = o;
        cnt[o]++;
    }
    rep(i, 0, n){
        cnt[c[i]]--;
        rep(j, 1, 11){
            ans += ten[j]*b[i]*cnt[j];
        }
    }
    cout << ans.val() << endl;
    return 0;
}