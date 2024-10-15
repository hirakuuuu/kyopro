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
    ll k; cin >> k;
    vector<ll> h(n), x(n), y(n);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, n) cin >> x[i] >> y[i];
    
    vector<vector<ll>> dist_square(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            dist_square[i][j] = dist_square[j][i] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        }
    }
    vector<vector<int>> g(n);
    vector<int> indegree(n);
    rep(i, 0, n){
        rep(j, i+1, n){
            if(h[i] > h[j]){
                if(dist_square[i][j] <= k*k){
                    g[i].push_back(j);
                    indegree[j]++;
                }
            }else if(h[i] < h[j]){
                if(dist_square[i][j] <= k*k){
                    g[j].push_back(i);
                    indegree[i]++;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 0, n){
        if(indegree[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}