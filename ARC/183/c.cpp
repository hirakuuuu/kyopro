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
    vector<int> l(m), r(m), x(m);
    vector<vector<vector<int>>> mid(n, vector<int>(n));
    rep(i, 0, m){
        cin >> l[i] >> r[i] >> x[i];
        l[i]--, r[i]--, x[i]--;
    }
    rep(i, 0, m){
        if(l[i] == r[i]){
            cout << 0 << endl;
            return 0;
        }
        mid[l[i]][r[i]].push_back(x[i]);
    }
    rep(i, 0, n) rep(j, i+1, n){
        sort(mid[i][j].begin(), mid[i][j].end());
        mid[i][j].erase(unique(mid[i][j].begin(), mid[i][j].end()), mid[i][j].end());
    }

    vector<vector<mint>> dp(n, vector<mint>(n));
    rep(i, 0, n) dp[i][i] = 1;
    rep(k, 1, n){
        rep(i, 0, n){
            // [i, i+k] の区間について，条件を満たすものを求める
            int j = i+k;
            dp[]
            for(auto mm: mid[i][j]){

            }
        }
    }
    return 0;
}