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
    vector<string> s(h);
    vector<vector<pair<int, int>>> a(26);
    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(inr(0, s[i][j]-'a', 26)){
                a[s[i][j]-'a'].emplace_back(i, j);
            }
        }
    }

    queue<pair<int, int>> que;
    que.push({0, 0});
    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<int> seen(26);
    dist[0][0] = 0;
    while(!que.empty()){
        auto [px, py] = que.front(); que.pop();
        {
            rep(k, 0, 4){
                int nx = px+(k-1)%2, ny = py+(k-2)%2;
                if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
                if(s[nx][ny] == '#') continue;
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[px][py]+1;
                que.push({nx, ny});
            }
        }
        if(s[px][py] != '.' && !seen[s[px][py]-'a']){
            seen[s[px][py]-'a'] = 1;
            for(auto [nx, ny]: a[s[px][py]-'a']){
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[px][py]+1;
                que.push({nx, ny});
            }           
        }
    }

    cout << dist[h-1][w-1] << endl;
    
    return 0;
}