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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sort(b.begin(), b.end());

    vector<ll> acc_b(m+1);
    rep(i, 1, m+1) acc_b[i] = acc_b[i-1]+b[i-1];

    mint ans = 0;
    rep(i, 0, n){
        int pos = upper_bound(b.begin(), b.end(), a[i])-b.begin();
        ans += mint(pos)*a[i]-acc_b[pos];
        ans += mint(acc_b[m]-acc_b[pos])-mint(m-pos)*a[i];
    }
    cout << ans.val() << endl;
    return 0;
}