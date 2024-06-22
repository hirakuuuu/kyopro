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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}




int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, 0, n){
        if(g[i].size()%2 == 1){
            cout << "No" << endl;
            return 0;
        }
    }

    map<pair<int, int>, bool> seen;
    auto dfs = [&](auto self, int u, vector<int> &trail) -> void {
        for(auto v: g[u]){
            if(seen[{u, v}]) continue;
            seen[{u, v}] = seen[{v, u}] = true;
            self(self, v, trail);
        }
        trail.push_back(u);
    };
    // vector<int> trail = {0, 3, 5, 4, 3, 6, 0, 1, 2, 0};
    vector<int> trail;
    dfs(dfs, 0, trail);   

    vector<vector<int>> cnt(n);
    rep(i, 1, trail.size()){
        cnt[trail[i]].push_back(i);
    }
    pair<int, int> l = {IINF, IINF};
    pair<int, int> r = {-IINF, -IINF};
    rep(i, 0, n){
        if(cnt[i].size() >= 3){
            cout << "Yes" << endl;
            return 0;
        }
        if(cnt[i].size() == 1) continue;
        if(i == 0){
            l = {0, cnt[0][0]}, r = {cnt[0][0], cnt[0][1]};
        }
        if(cnt[i][1] < l.second){
            l = {cnt[i][0], cnt[i][1]};
        }
        if(r.first < cnt[i][0]){
            r = {cnt[i][0], cnt[i][1]};
        }
    }
    // cout << l.first << ' ' << l.second << ' ' << r.first << ' ' << r.second << endl;
    if(l.second < r.first){
        cout << "Yes" << endl;
        return 0;
    }

    vector<int> mi(trail.size()+1, IINF);
    rep(i, 0, n){
        if(cnt[i].size() == 1) continue;
        mi[cnt[i][0]] = cnt[i][1];
    }
    rrep(i, trail.size()-1, 1){
        chmin(mi[i], mi[i+1]);
        if(cnt[trail[i]].size() == 1) continue;
        // cout << i << ' ' << mi[i+1] << endl;
        if(cnt[trail[i]][0] == i && mi[i+1] < cnt[trail[i]][1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(cnt[0].size() == 2){
        rep(i, 1, n){
            if(cnt[i].size() == 1) continue;
            if(cnt[i][1] < cnt[0][0]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    
    cout << "No" << endl;
    return 0;
}