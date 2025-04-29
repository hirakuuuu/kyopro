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
    vector<vector<long double>> prob(n, vector<long double>(100005));
    vector<vector<int>> a(n);
    rep(i, 0, n){
        int k; cin >> k;
        long double dk = (long double)k;
        a[i].resize(k);
        rep(j, 0, k){
            cin >> a[i][j]; a[i][j]--;
            prob[i][a[i][j]] += 1.0/dk;
        }
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
    }

    long double ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            long double tmp = 0.0;
            for(auto aa: a[j]){
                // cout << aa << ' ' << prob[i][aa] << ' ' << prob[j][aa] << endl;
                tmp += prob[i][aa]*prob[j][aa];
            }
            // cout << i << ' ' << j << ' ' << setprecision(20) << tmp << endl;
            chmax(ans, tmp);
        }
    }
    cout << setprecision(20) << ans << endl;

   
    return 0;
}