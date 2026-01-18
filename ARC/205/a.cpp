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
    int q; cin >> q;
    vector<string> s(n);
    rep(i, 0, n){
        cin >> s[i];
    }

    vector<vector<int>> cnt(n+1, vector<int>(n+1));
    rep(i, 1, n) rep(j, 1, n){
        cnt[i+1][j+1] = cnt[i][j+1]+cnt[i+1][j]-cnt[i][j];
        if(s[i-1][j-1] == '.' && s[i][j-1] == '.' && s[i-1][j] == '.' && s[i][j] == '.'){
            cnt[i+1][j+1]++;
        }
    }
    // cout << '#' << endl;

    while(q--){
        int u, d, l, r; cin >> u >> d >> l >> r;
        u--, l--;
        // cout << cnt[d][r] << ' ' << cnt[d][l] << ' ' cnt[u][r] << ' ' << cnt[u][l] << endl;
        int ans = cnt[d][r]-cnt[d][l+1]-cnt[u+1][r]+cnt[u+1][l+1];
        cout << ans << endl;
    }

    

    return 0;
}