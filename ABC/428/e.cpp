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
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q_]+1;
            que.push(nq);
        }
    }
    int L = n-1;
    rrep(i, n-1, 0){
        if(dist[L] < dist[i]) L = i;
    }

    fill(dist.begin(), dist.end(), -1);
    que.push(L);
    dist[L] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q_]+1;
            que.push(nq);
        }
    }
    int R = n-1;
    rrep(i, n-1, 0){
        if(dist[R] < dist[i]) R = i;
    }

    if(L > R) swap(L, R);

    vector<int> dist_L(n, -1), dist_R(n, -1);
    dist_L[L] = 0;
    que.push(L);
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist_L[nq] != -1) continue;
            dist_L[nq] = dist_L[q_]+1;
            que.push(nq);
        }
    }
    dist_R[R] = 0;
    que.push(R);
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist_R[nq] != -1) continue;
            dist_R[nq] = dist_R[q_]+1;
            que.push(nq);
        }
    }

    rep(i, 0, n){
        if(dist_L[i] > dist_R[i]) cout << L+1 << endl;
        else cout << R+1 << endl;
    }
    
    return 0;
}