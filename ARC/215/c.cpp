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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<pair<int, int>>> g(n);
        int mx_x = -1;
        rep(i, 0, n){
            int x, y, z; cin >> x >> y >> z; 
            x--, y--, z--;
            chmax(mx_x, x);
            g[x].push_back({y, z});
        }
        rep(i, 0, n){
            sort(g[i].begin(), g[i].end());
        }

        int ans = g[mx_x].size();
        int mi_y = n, mi_z = n;
        {
            for(auto [y, z]: g[mx_x]){
                chmin(mi_y, y);
                chmin(mi_z, z);
            }
        }
        vector<vector<pair<int, int>>> cnt(n);
        int l = mx_x-1, r = mx_x;
        rrep(x, mx_x-1, 0){
            for(auto [y, z]: g[x]){
                if(mi_y <= y || mi_z <= z){
                    r = x;
                    ans++;
                    chmin(mi_y, y);
                    chmin(mi_z, z);
                }else{
                    cnt[x].push_back({y, z});
                }
            }
            if(r == x){
                while(l >= r){
                    for(auto [y, z]: cnt[l]){
                        ans++;
                        chmin(mi_y, y);
                        chmin(mi_z, z);
                    }
                    l--;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}