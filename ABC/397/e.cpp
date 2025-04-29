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

/*
長さ k のパスに分解するためには，そもそもサイズ k の部分木に分解できなければだめ．
木DP の要領でサイズが k 以下になるように部分木をつくり，それがパスであるかを判定する．
再帰的に見ていくことから，各段階で根の次数だけをチェックすればよい．
*/

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n*k);
    rep(i, 0, n*k-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> s(n*k, 1);
    auto f = [&](auto self, int pos, int pre) -> bool {
        bool res = true;
        int c = 0;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            res &= self(self, nxt, pos);
            s[pos] += s[nxt];
            if(s[nxt] > 0) c++;
        }
        // cout << pos << ' ' << s[pos] << ' ' << c << endl;
        if(s[pos] < k){
            if(c >= 2){
                res = false;
            }
        }
        if(s[pos] > k){
            res = false;
        }
        if(s[pos] == k){
            if(c >= 3){
                res = false;
            }else{
                s[pos] = 0;
            }
        }
        return res;
    };

    if(f(f, 0, -1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}