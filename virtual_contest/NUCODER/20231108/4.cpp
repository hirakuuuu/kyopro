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
// 

int n, t;
vector<vector<int>> enemy(15);
vector<int> team(15, -1);
int f(vector<int> &team, int cur){
    set<int> teams;
    rep(i, 0, n){
        if(team[i] != -1) teams.insert(team[i]);
    }
    if(t-teams.size() > n-cur) return 0;
    if(cur == n) return 1;

    set<int> enemys;
    for(auto ee: enemy[cur]){
        if(team[ee] != -1) enemys.insert(team[ee]);
    }

    int r = t, res = 0;
    if(teams.empty()) r = 0;
    else r = min(t-1, *teams.rbegin()+1);

    rep(i, 0, r+1){
        if(enemys.find(i) != enemys.end()) continue;
        team[cur] = i;
        res += f(team, cur+1);
        team[cur] = -1;
    }

    return res;
}

int main(){
    int m; cin >> n >> t >> m;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        enemy[a].push_back(b);
        enemy[b].push_back(a);
    }
    cout << f(team, 0) << endl;



    
    
    return 0;
}