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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> cnt(100005);
    rep(i, 0, n) cnt[a[i]]++;

    ll sum = 0;
    rep(i, 0, n) sum += a[i];
    
    int q; cin >> q;
    while(q--){
        ll b, c; cin >> b >> c;
        sum -= cnt[b]*b;
        sum += cnt[b]*c;
        cnt[c] += cnt[b];
        cnt[b] = 0;
        cout << sum << endl;
    }
    
    return 0;
}