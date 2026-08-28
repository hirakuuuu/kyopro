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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> b(n);
    rep(i, 0, n){
        cin >> b[i];
    }
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
    }

    set<pair<int, int>> s;
    rep(i, 0, n){
        s.insert({b[i], i});
    }
    int first = 1;
    vector<int> seen(n);
    vector<int> ans;
    while(!s.empty()){
        int pos = -1;
        if(first){
            pos = 0;
            first = 0;
        }else{
            pos = (*s.rbegin()).second;
        }
        
        while(true){
            seen[pos] = 1;
            ans.push_back(pos);
            s.erase({b[pos], pos});
            int mx = -1, id = -1;
            for(auto nxt: g[pos]){
                if(seen[nxt]) continue;
                if(mx < b[nxt]){
                    mx = b[nxt];
                    id = nxt;
                }
            }
            if(id == -1) break;
            pos = id;
        }
    }

    rep(i, 0, n){
        cout << ans[i]+1 << ' ';
    }
    cout << endl;
    return 0;
}