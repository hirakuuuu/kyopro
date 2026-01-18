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
    int n, x; cin >> n >> x;
    vector<vector<pair<int, int>>> food(3);
    rep(i, 0, n){
        int v; cin >> v; v--;
        int a, c; cin >> a >> c;
        food[v].push_back({a, c});
    }

    vector<vector<int>> mx(3);
    rep(i, 0, 3){
        vector<int> dp(x+1);
        rep(j, 0, food[i].size()){
            vector<int> ndp = dp;
            rep(k, 0, x+1){
                if(k >= food[i][j].second){
                    chmax(ndp[k], dp[k-food[i][j].second]+food[i][j].first);
                }
            }
            swap(ndp, dp);
        }
        mx[i] = dp;
    }

    ll ans = 0;
    for(int i = 0; i <= x; i++){
        for(int j = 0; i+j <= x; j++){
            chmax(ans, min({mx[0][i], mx[1][j], mx[2][x-i-j]}));
        }
    }
    cout << ans << endl;
    
    return 0;
}