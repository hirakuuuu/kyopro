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
// using mint = modint998244353;
using mint = modint;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, k, m; cin >> n >> k >> m;
    mint::set_mod(m);
    vector<vector<mint>> cnt(n, vector<mint>(k*n*(n-1)/2+1));
    cnt[0][0] = 1;
    rep(i, 1, n){
        vector<mint> sum(i);
        rep(j, 0, k*i*(i+1)/2+1){
            cnt[i][j] = cnt[i-1][j];
            cnt[i][j] += sum[j%i];

            sum[j%i] += cnt[i-1][j];
            if(j-k*i >= 0) sum[j%i] -= cnt[i-1][j-k*i];
        }
    }
    rep(i, 1, n+1){
        mint ans = k;
        mint tmp = k+1;
        rep(j, 1, k*n*(n-1)/2+1){
            ans += tmp*cnt[i-1][j]*cnt[n-i][j];
        }
        cout << ans.val() << endl;
    }
    
    return 0;
}