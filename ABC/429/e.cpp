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
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s; cin >> s;

    queue<pair<int, int>> que;
    map<pair<int, int>, int> d1;
    map<pair<int, int>, int> d2;
    vector<int> nearest_S(n, -1);
    vector<int> second_nearest_S(n, -1);
    rep(i, 0, n){
        if(s[i] == 'S'){
            que.push({i, i});
            d1[{i, i}] = 0;
            nearest_S[i] = i;
        }
    }
    while(!que.empty()){
        auto [q, start] = que.front(); que.pop();
        for(auto nq: g[q]){
            if(nearest_S[nq] == -1){
                d1[{nq, start}] = d1[{q, start}]+1;
                nearest_S[nq] = start;
                que.push({nq, start});
            }else if(second_nearest_S[nq] == -1){
                if(nearest_S[nq] == start) continue;
                if(d1.count({q, start})) d2[{nq, start}] = d1[{q, start}]+1;
                else if(d2.count({q, start})) d2[{nq, start}] = d2[{q, start}]+1;
                else assert(false);
                second_nearest_S[nq] = start;
                que.push({nq, start});
            }
        }
    }

    rep(i, 0, n){
        if(s[i] == 'D'){
            cout << d1[{i, nearest_S[i]}]+d2[{i, second_nearest_S[i]}] << endl;
        }
    }
    
    
    return 0;
}