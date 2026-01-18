#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define ti tuple<int, int, int, int, int, int>

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    pair<int, int> t;
    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(s[i][j] == 'T'){
                t = {i, j};
            }
        }
    }
    queue<tuple<vector<int>, int, int>> que;
    que.push({{0, 0, 0, 0}, t.first, t.second});
    // ULDR
    map<tuple<vector<int>, int, int>, int> memo;
    memo[que.front()] = 0;
    int ans = -1;
    while(!que.empty()){
        auto [d, px, py] = que.front(); que.pop();
        int pd = memo[{d, px, py}];
        bool ok = true;
        rep(i, 0, h){
            rep(j, 0, w){
                if(s[i][j] == '#'){
                    if(!inr(0, i-d[0], h) || !inr(0, j-d[1], w) || !inr(0, i-d[2], h) || !inr(0, j-d[3], w)) continue;
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok){
            ans = pd;
            break;
        }
        
        rep(k, 0, 4){
            int nx = px+(k-1)%2, ny = py+(k-2)%2;
            int tx = t.first-(nx-t.first), ty = t.second-(ny-t.second);
            if(inr(0, nx, h) && inr(0, ny, w) && s[nx][ny] == '#'){
                if(!inr(0, nx-d[0], h) || !inr(0, ny-d[1], w) || !inr(0, nx-d[2], h) || !inr(0, ny-d[3], w)){

                }else{
                    continue;
                }
            }
            vector<int> nd = d;
            chmin(nd[0], nx-t.first);
            chmin(nd[1], ny-t.second);
            chmax(nd[2], nx-t.first);
            chmax(nd[3], ny-t.second);
            if(memo.count({nd, nx, ny})) continue;
            memo[{nd, nx, ny}] = pd+1;
            que.push({nd, nx, ny});
        }
    }
    cout << ans << endl;

    
    return 0;
}