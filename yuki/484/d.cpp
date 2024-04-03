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
    int s, t, k; cin >> s >> t >> k;
    s--, t--;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n == 1){
        cout << "No" << endl;
        return 0;
    }
    if(m == 0){
        if(n == 2 && s != t && k%2 == 0) cout << "No" << endl;
        else if(n == 2 && s == t && k%2 == 1) cout << "No" << endl;
        else cout << "Unknown" << endl;
        return 0;
    }

    vector<int> dist(n, -1);
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }
    int not_reach = 0, same_group = 0, diff_group = 0;
    rep(i, 0, n){
        if(dist[i] == -1) not_reach++;
        else if(dist[s] == dist[i]) same_group++;
        else diff_group++;
    }

    if(dist[t] != -1){
        if((dist[t]%2 == 0 && k%2 == 1) || (dist[t]%2 == 1 && k%2 == 0)){
            cout << "No" << endl;
            return 0;
        }
        if(k < dist[t]) cout << "Unknown" << endl;
        else cout << "Yes" << endl;
    }else{
        if(k%2 == 0){
            if(n <= 2 && m == 0) cout << "No" << endl;
            else cout << "Unknown" << endl;
        }else{
            cout << "Unknown" << endl;
        }
    }






    
    return 0;
}