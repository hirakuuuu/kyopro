#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc233/tasks/abc233_f

int main(){
    int n; cin >> n;
    vector<int> p(n), pos(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    int m; cin >> m;
    vector<vector<int>> g(n), c(n, vector<int>(n));
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        c[a][b] = c[b][a] = i+1;
    }

    vector<vector<int>> dist(n, vector<int>(n, -1));
    rep(i, 0, n) dist[i][i] = 0;
    rep(i, 0, n){
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(dist[i][nq] != -1) continue;
                dist[i][nq] = dist[i][q]+1;
                que.push(nq);
            }
        }
    }

    vector<int> ans;
    rep(i, 0, n){
        if(dist[i][pos[i]] == -1){
            cout << -1 << endl;
            return 0;
        }

        int tmp = pos[i];
        vector<tuple<int, int, int>> rev;
        while(tmp != i){
            for(auto nxt: g[tmp]){
                if(dist[i][nxt] == dist[i][tmp]-1){
                    ans.push_back(c[tmp][nxt]);
                    if(nxt != i) rev.push_back({c[tmp][nxt], tmp, nxt});
                    swap(p[tmp], p[nxt]);
                    swap(pos[p[tmp]], pos[p[nxt]]);
                    tmp = nxt;
                    break;
                }
            }
        }
        reverse(rev.begin(), rev.end());
        for(auto [r, t, nt]: rev){
            ans.push_back(r);
            swap(p[t], p[nt]);
            swap(pos[p[t]], pos[p[nt]]);
        }
    }

    vector<int> cor(n);
    iota(cor.begin(), cor.end(), 0);
    if(p == cor && ans.size() > 500000){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;
    
    
    return 0;
}