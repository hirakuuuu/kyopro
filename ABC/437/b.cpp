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
    int h, w; cin >> h >> w;
    int n; cin >> n;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> cnt(h, vector<int>(100));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
            cnt[i][a[i][j]]++;
        }
    }
    vector<int> b(n);
    rep(i, 0, n) cin >> b[i];

    int ans = 0;
    rep(i, 0, h){
        int tot = 0;
        rep(j, 0, n) tot += cnt[i][b[j]];
        chmax(ans, tot);
    }
    cout << ans << endl;
    return 0;
}