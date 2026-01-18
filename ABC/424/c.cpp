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
    vector<vector<int>> g(n);
    vector<int> ind(n);
    rep(i, 0, n){
        int a, b; cin >> a >> b; a--, b--;
        if(a == -1) continue;
        g[a].push_back(i);
        g[b].push_back(i);
        ind[i]++;
        ind[i]++;
    }

    queue<int> que;
    vector<int> seen(n);
    rep(i, 0, n){
        if(ind[i] <= 1) que.push(i), seen[i] = 1;
    }
    int ans = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        ans++;
        for(auto nq: g[q]){
            if(seen[nq]) continue;
            ind[nq]--;
            if(ind[nq] <= 1) que.push(nq), seen[nq] = 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}