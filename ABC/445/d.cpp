#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<int> x(n), y(n);
    unordered_map<int, vector<int>> mpx, mpy;
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        mpx[x[i]].push_back(i);
        mpy[y[i]].push_back(i);
    }

    vector<pair<int, int>> ans(n, {-1, -1});
    int ph = h, pw = w;
    while(ph > 0 && pw > 0){
        {
            for(auto id: mpx[ph]){
                if(ans[id].first != -1) continue;
                ans[id] = {0, pw-y[id]};
                pw -= y[id];
            }
        }
        {
            for(auto id: mpy[pw]){
                if(ans[id].first != -1) continue;
                ans[id] = {ph-x[id], 0};
                ph -= x[id];
            }
        }
    }

    rep(i, 0, n){
        cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
    }
    
    return 0;
}