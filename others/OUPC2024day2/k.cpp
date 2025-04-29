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
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string s; cin >> s;

    vector<vector<mint>> cnt(n, vector<mint>(26));
    vector<vector<vector<int>>> ng(n, vector<vector<int>>(26));
    rep(i, 0, n){
        for(auto j: g[i]){
            cnt[i][s[j]-'a']++;
            ng[i][s[j]-'a'].push_back(j);
        }
    }

    mint ans = 0;
    rep(c, 0, n){
        // v_2 = c とした場合を数える
        int o = s[c]-'a';
        rep(e, 0, 26){
            if(o == e) continue;
            mint tot = 0; 
            for(auto adj: ng[c][e]){
                // cout << e << ' ' << o << ' ' << cnt[c][e].val() << ' ' << cnt[adj][o].val() << endl;
                tot += cnt[adj][o];
            }
            // cout << c << ' ' << o << ' ' << e << ' ' << tot.val() << endl;
            ans += tot*tot;
        }
        // cout << c << ' ' << ans.val() << endl;
    }
    cout << ans.val() << endl;
    
    return 0;
}