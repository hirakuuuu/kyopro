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
// https://atcoder.jp/contests/arc161/tasks/arc161_c

bool dfs(int pos, int p, vector<vector<int>> &g, vector<int> &s, vector<int> &t){
    int f = 0;


    for(auto ns: g[pos]){
        if(ns == p) continue;
        if(!dfs(ns, pos, g, s, t)){
            return false;
        }
        if(s[pos] == t[ns]) f++;
    }

    if(p != -1 && t[pos] == -1) t[pos] = s[p];
    else if(t[pos] == -1) t[pos] = 1;
    if(p == -1){
        if(f <= (g[pos].size()-1)/2) return false;
    }else{
        if(f < (g[pos].size()-1)/2) return false;
        else if(f == (g[pos].size()-1)/2){
            if(t[p] != -1 && t[p] != s[pos]) return false;
            t[p] = s[pos];
        }
    }

    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> g(n);
        g[0].push_back(-1);
        rep(i, 0, n-1){
            int a, b; cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        string s; cin >> s;
        vector<int> c(n), ans(n, -1);
        rep(i, 0, n){
            if(s[i] == 'B') c[i] = 1;
        }

        if(dfs(0, -1, g, c, ans)){
            rep(i, 0, n){
                if(ans[i]) cout << 'B';
                else cout << 'W';
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    
    return 0;
}