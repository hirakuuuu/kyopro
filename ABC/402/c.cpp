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
    vector<vector<int>> to(n);
    vector<int> ind(m);
    rep(i, 0, m){
        int k; cin >> k;
        rep(j, 0, k){
            int a; cin >> a; a--;
            to[a].push_back(i);
            ind[i]++;
        }
    }

    int ans = 0;
    
    rep(i, 0, n){
        int b; cin >> b; b--;
        for(auto t: to[b]){
            ind[t]--;
            if(ind[t] == 0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}