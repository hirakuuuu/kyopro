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

int main(){
    int x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, 0, x) cin >> a[i];
    rep(i, 0, y) cin >> b[i];
    rep(i, 0, z) cin >> c[i];
    vector<ll> ab(x*y);
    rep(i, 0, x){
        rep(j, 0, y){
            ab[i*y+j] = a[i]+b[j];
        }
    }
    sort(ab.rbegin(), ab.rend());
    while(ab.size() <= k) ab.push_back(0LL);
    vector<ll> ab_(k);
    rep(i, 0, k) ab_[i] = ab[i];
    swap(ab_, ab);
    vector<ll> abc(k*z);
    rep(i, 0, k){
        rep(j, 0, z){
            abc[i*z+j] = ab[i]+c[j];
        }
    }
    sort(abc.rbegin(), abc.rend());
    rep(i, 0, k){
        cout << abc[i] << endl;
    }
    
    return 0;
}