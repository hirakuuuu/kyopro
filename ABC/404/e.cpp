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
    int n; cin >> n;
    vector<int> c(n), a(n);
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) cin >> a[i];

    vector<int> dist(n, IINF); // 豆が1個以上入っているところへの最短距離
    dist[0] = 0;
    rep(i, 1, n){
        rep(j, i-c[i], i){
            if(a[j] > 0) dist[i] = 1;
            else chmin(dist[i], dist[j]+1);
        }
        // cout << i << ' ' << dist[i] << endl;
    }

    int ans = 0;
    rrep(i, n-1, 1){
        if(a[i] == 0) continue;
        ans += dist[i];
    }
    cout << ans << endl;
    
    return 0;
}