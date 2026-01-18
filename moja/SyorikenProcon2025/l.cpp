
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
constexpr ll MOD = 4736947;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w, K; cin >> h >> w >> K;
    vector<string> s(h);
    int num_p = 0;
    int num_b = 0;
    map<pair<int, int>, int> p;
    map<pair<int, int>, int> b;

    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(s[i][j] == '#'){
                b[{i, j}] = num_b;
                num_b++;
            }else if(s[i][j] == 'P'){
                p[{i, j}] = num_p;
                num_p++;
            }
        }
    }
    for(auto &[key, _]: b){
        b[key] += num_p;
    }
    int num_pb = num_p+num_b;
    vector<vector<vector<int>>> br(4, vector<vector<int>>(h, vector<int>(w, (1<<num_pb)-1)));
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '.') continue;
            int num = 0;
            if(s[i][j] == '#') num = 1<<b[{i, j}];                
            if(s[i][j] == 'P') num = 1<<p[{i, j}];        
            // cout << num << endl;        
            
            rep(k, 0, 4){
                int di = (k-1)%2, dj = (k-2)%2;
                int ni = i, nj = j;
                rep(_, 0, K){
                    ni += di, nj += dj;
                    if(!inr(0, ni, h) || !inr(0, nj, w)) break;
                    br[(k^2)][ni][nj] -= num;
                }
            }
        }
    }

    vector<vector<vector<int>>> dp(1<<num_pb, vector<vector<int>>(h, vector<int>(w, IINF)));
    dp[(1<<num_pb)-1][0][0] = 0;
    queue<tuple<int, int, int>> que;
    que.push({(1<<num_pb)-1, 0, 0});
    while(!que.empty()){
        auto [state, px, py] = que.front(); que.pop();
        // 移動
        rep(k, 0, 4){
            int nx = px+(k-1)%2, ny = py+(k-2)%2;
            // cout << state << ' ' << nx << ' ' << ny << endl;

            if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
            if(s[nx][ny] == '#' && (state>>b[{nx, ny}])&1) continue;
            int nstate = state;
            // cout << nstate << ' ' << nx << ' ' << ny << endl;
            if(s[nx][ny] == 'P' && (nstate>>p[{nx, ny}])&1) nstate -= 1<<p[{nx, ny}];
            if(dp[nstate][nx][ny] != IINF) continue;
            dp[nstate][nx][ny] = dp[state][px][py]+1;
            que.push({nstate, nx, ny}); 
        }
        // ブレス
        rep(k, 0, 4){
            int nstate = br[k][px][py]&state;
            // cout << nstate << ' ' << px << ' ' << py << endl;
            if((state-nstate)&((1<<num_p)-1)) continue;
            if(dp[nstate][px][py] != IINF) continue;
            dp[nstate][px][py] = dp[state][px][py]+1;
            que.push({nstate, px, py});
        }
    }

    int ans = IINF;
    rep(i, 0, 1<<num_pb){
        if(i&((1<<num_p)-1)) continue;
        // cout << i << endl;
        rep(j, 0, h){
            rep(l, 0, w){
                // cout << dp[i][j][l] << ' ';
                chmin(ans, dp[i][j][l]);
            }
            // cout << endl;
        }
    }
    if(ans == IINF) ans = -1;
    cout << ans << endl;

    return 0;
}