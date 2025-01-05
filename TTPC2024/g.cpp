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
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> ans(n);
    auto f = [&](auto self, int pos, int pre) -> int {
        
        int cnt = 0, mx = 0, mx_cnt = 0;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            cnt++;
            ans[nxt] = self(self, nxt, pos);
            
            if(mx == ans[nxt]){
                mx_cnt++;
            }else if(mx < ans[nxt]){
                mx = ans[nxt];
                mx_cnt = 1;
            }
        }

        if(cnt == 0){
            return ans[pos] = 1;
        }
        if(mx_cnt >= 2){
            return ans[pos] = mx+1;
        }

        return ans[pos] = mx;
    };

    f(f, 0, -1);
    cout << ans[0] << endl;
    return 0;
}