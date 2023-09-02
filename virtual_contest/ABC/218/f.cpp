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

int main(){
    int n, m; cin >> n >> m; 
    vector<int> s(m), t(m);
    vector<vector<int>> g(n);
    vector<vector<int>> rev_g(n);
    map<pair<int, int>, int> eid;
    rep(i, 0, m){
        cin >> s[i] >> t[i];
        s[i]--, t[i]--;
        eid[{s[i], t[i]}] = i;
        g[s[i]].push_back(t[i]);
        rev_g[t[i]].push_back(s[i]);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }

    // そもそもたどり着けない
    if(dist[n-1] == -1){
        rep(i, 0, m){
            cout << -1 << '\n';
        }
        return 0;
    }

    vector<int> ans(m, dist[n-1]);
    vector<pair<int, int>> se;
    int p = n-1;
    while(p != 0){
        int tmp = dist[p];
        for(auto rp: rev_g[p]){
            if(dist[rp] == tmp-1){
                se.push_back({rp, p});
                p = rp;
                break;
            }
        }
    }

    for(auto pp: se){
        vector<vector<int>> ng(n);
        rep(i, 0, m){
            if(make_pair(s[i], t[i]) == pp) continue;
            ng[s[i]].push_back(t[i]);
        }
        fill(dist.begin(), dist.end(), -1);
        dist[0] = 0;
        que.push(0);
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: ng[q]){
                if(dist[nq] != -1) continue;
                dist[nq] = dist[q]+1;
                que.push(nq);
            }
        }
        ans[eid[pp]] = dist[n-1];
    }

    rep(i, 0, m){
        cout << ans[i] << '\n';
    }

    
    return 0;
}