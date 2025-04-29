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
    int n; cin >> n;
    vector<int> u(n), v(n);
    vector<vector<int>> g(n);
    map<pair<int, int>, bool> used;

    rep(i, 0, n-1){
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        used[{min(u[i], v[i]), max({u[i], v[i]})}] = true;
    }

    vector<int> b(n, -1);
    b[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(b[nq] != -1) continue;
            b[nq] = 1-b[q];
            que.push(nq);
        }
    }
    vector<pair<int, int>> ok;
    rep(i, 0, n){
        rep(j, i+1, n){
            if(b[i] == b[j]) continue;
            if(used[{i, j}]) continue;
            ok.push_back({i, j});
        }
    }
    int pos = 0;
    if(ok.size()%2 == 1){
        cout << "First" << endl;
        while(true){
            while(pos < ok.size() && used[ok[pos]]) pos++;
            used[ok[pos]] = true;
            cout << ok[pos].first+1 << ' ' << ok[pos].second+1 << endl;
            pos++;

            int ti, tj; cin >> ti >> tj;
            if(ti == -1) break;
            used[{ti-1, tj-1}] = true;
        }
    }else{
        cout << "Second" << endl;
        while(true){
            int ti, tj; cin >> ti >> tj;
            if(ti == -1) break;
            used[{ti-1, tj-1}] = true;

            while(pos < ok.size() && used[ok[pos]]) pos++;
            used[ok[pos]] = true;
            cout << ok[pos].first+1 << ' ' << ok[pos].second+1 << endl;
            pos++;
        }
    }


    
    return 0;
}