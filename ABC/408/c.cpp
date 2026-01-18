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

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n+2);
    rep(i, 0, m){
        int l, r; cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }

    rep(i, 1, n+2) a[i] += a[i-1];

    int ans = IINF;
    rep(i, 1, n+1) chmin(ans, a[i]);
    cout << ans << endl;
    
    return 0;
}