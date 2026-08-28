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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, K; cin >> h >> w >> K;
    vector<string> s(h);
    vector<int> ei(h), ej(w);
    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(s[i][j] == '#'){
                ei[i] = ej[j] = 1;
            }
        }
    }

    queue<pair<int, int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i, 0, h){
        rep(j, 0, w){
            if(!ei[i] && !ej[j]){
                que.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int ans = 0;
    while(!que.empty()){
        ans++;
        auto [pi, pj] = que.front(); que.pop();
        if(K == 0) continue;
        rep(k, 0, 4){
            int ni = pi+(k-1)%2, nj = pj+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(s[ni][nj] == '#') continue;
            if(dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[pi][pj]+1;
            if(dist[ni][nj] < K) que.push({ni, nj});
            else ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}