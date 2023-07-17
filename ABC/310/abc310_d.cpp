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
// https://atcoder.jp/contests/abc310/tasks/abc310_d

vector<int> g(100);
vector<int> teams;

int dfs(int now, int &n, int &t){
    if(now == n) return teams.size() == t;

    int ans = 0;
    for(auto &team: teams){
        if(!(team & g[now])){
            team ^= 1 << now;
            ans += dfs(now+1, n, t);
            team ^= 1 << now;
        }
    }

    if(teams.size() < t){
        teams.emplace_back(1<<now);
        ans += dfs(now+1, n, t);
        teams.pop_back();
    }

    return ans;
}



int main(){
    int n, t, m; cin >> n >> t >> m;
    vector<int> a(m), b(m);

    rep(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]] |= (1<<b[i]);
        g[b[i]] |= (1<<a[i]);
    }

    teams.reserve(t);
    cout << dfs(0, n, t) << endl;



    return 0;
}