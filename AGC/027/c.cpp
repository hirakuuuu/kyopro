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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    vector<int> col(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
        if(s[a] == 'A') col[b]++;
        else col[b]--;
        if(s[b] == 'A') col[a]++;
        else col[a]--;
    }

    queue<int> que;
    vector<int> seen(n);
    rep(i, 0, n){
        if(abs(col[i]) == deg[i]){
            que.push(i);
            seen[i] = true;
        }

    }
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(seen[nq]) continue;
            deg[nq]--;
            if(s[q] == 'A') col[nq]--;
            else col[nq]++;
            if(abs(col[nq]) == deg[nq]){
                que.push(nq);
                seen[nq] = true;
            }
        }
    }

    bool f = false;
    rep(i, 0, n){
        if(seen[i] == 0) f = true;
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}