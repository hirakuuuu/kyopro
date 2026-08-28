#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

vector<int> di = {-1, 0, 0};
vector<int> dj = {0, 1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    int sum = 0;
    rep(i, 0, h) rep(j, 0, w) if(s[i][j] == '+') sum++;

    mf_graph<int> g(h*w+2);
    int source = h*w, target = source+1;

    vector<vector<int>> seen(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '+'){
                g.add_edge(source, i*w+j, 1);
                rep(ii, 0, h) rep(jj, 0, w) seen[ii][jj] = 0;
                queue<pair<int, int>> que;
                que.push({i, j});
                seen[i][j] = 1;
                while(!que.empty()){
                    auto [pi, pj] = que.front(); que.pop();
                    rep(k, 0, 3){
                        int ni = pi+di[k], nj = pj+dj[k];
                        if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                        if(s[ni][nj] == '#') continue;
                        if(seen[ni][nj]) continue;
                        que.push({ni, nj});
                        seen[ni][nj] = 1;
                        if(s[ni][nj] == '-'){
                            g.add_edge(i*w+j, ni*w+nj, 1);
                        }
                    }
                }
            }else if(s[i][j] == '-'){
                g.add_edge(i*w+j, target, 1);
            }
        }
    }
    cout << sum-g.flow(source, target) << endl;
    
    return 0;
}