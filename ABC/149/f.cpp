#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> c(n);
    mint ans = 0;
    auto f = [&](auto self, int pos, int pre) -> void {

        vector<int> children;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            children.push_back(c[nxt]+1);
            c[pos] += c[nxt]+1;
        }

        if(pre != -1) children.push_back(n-c[pos]-1);
        if(children.size() >= 2){
            mint pr = mint(2).inv().pow(n);
            for(auto cc: children){
                pr += mint(2).inv().pow(n-cc)*(1-mint(2).inv().pow(cc));
            }
            ans += mint(2).inv()-pr;
        }
    };
    f(f, 0, -1);
    cout << ans.val() << endl;
    return 0;
}