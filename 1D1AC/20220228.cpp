#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<pll>> g(2005);
vector<vector<ll>> d(2005, vector<ll>(2005, (1LL<<50)));
vector<vector<ll>> dist(2005, vector<ll>(2005, (1LL<<50)));

void dijk(int s){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push(make_pair(0, s));
    dist[s][s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        for(auto ns: g[q.second]){
            if(dist[s][ns.second] > dist[s][q.second]+ns.first){
                dist[s][ns.second] = dist[s][q.second]+ns.first;
                que.push(make_pair(dist[s][ns.second], ns.second));
            }
        }
    }
}


int main(){
    int n, m; cin >> n >> m;
    vector<ll> self_d(2005, (1LL<<50));
    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        if(a==b) self_d[a] = min(self_d[a], c);
        else d[a][b] = min(d[a][b], c);
    }
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            if(d[i][j] != (1LL << 50)){
                g[i].push_back(make_pair(d[i][j], j));
            }
        }
    }
    rep(k, 1, n+1){
        dijk(k);
    }

    rep(k, 1, n+1){
        ll mc = (1LL<<50);
        rep(i, 1, n+1){
            if(i == k) continue;
            mc = min(mc, dist[k][i]+dist[i][k]);
        }
        mc = min(mc, self_d[k]);
        if(mc != (1LL<<50)) cout << mc << endl;
        else cout << -1 << endl;
    } 
}