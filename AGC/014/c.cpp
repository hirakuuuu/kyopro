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
    int h, w; cin >> h >> w;
    int K; cin >> K;
    vector<string> a(h);
    int si, sj;
    rep(i, 0, h){
        cin >> a[i];
        rep(j, 0, w){
            if(a[i][j] == 'S'){
                si = i, sj = j;
            }
        }
    }

    queue<pair<int, int>> que;
    queue<pair<int, int>> que2;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[si][sj] = 0;
    que.push({si, sj});
    que2.push({si, sj});
    while(!que.empty()){
        auto [qi, qj] = que.front(); que.pop();
        rep(k, 0, 4){
            int ni = qi+(k-1)%2, nj = qj+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(a[ni][nj] == '#') continue;
            if(dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[qi][qj]+1;
            que2.push({ni, nj});
            if(dist[ni][nj] < K) que.push({ni, nj});
        }
    }
    rep(i, 0, h) rep(j, 0, w){
        if(dist[i][j] != -1) dist[i][j] = K;
    }

    
    while(!que2.empty()){
        auto [qi, qj] = que2.front(); que2.pop();
        rep(k, 0, 4){
            int ni = qi+(k-1)%2, nj = qj+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[qi][qj]+1;
            que2.push({ni, nj});
        }
    }
    
    
    int ans = IINF;
    rep(i, 0, w){
        chmin(ans, (dist[0][i]+K-1)/K);
        chmin(ans, (dist[h-1][i]+K-1)/K);
    }
    rep(i, 0, h){
        chmin(ans, (dist[i][0]+K-1)/K);
        chmin(ans, (dist[i][w-1]+K-1)/K);
    }
    cout << ans << endl;
    return 0;
}