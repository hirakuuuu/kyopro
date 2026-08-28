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
    int si, sj, gi, gj;
    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(s[i][j] == 'S'){
                si = i, sj = j;
            }else if(s[i][j] == 'G'){
                gi = i, gj = j;
            }
        }
    }

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4, IINF)));
    vector<vector<vector<tuple<int, int, int>>>> pre(h, vector<vector<tuple<int, int, int>>>(w, vector<tuple<int, int, int>>(4, {-1, -1, -1})));
    queue<tuple<int, int, int>> que;
    rep(i, 0, 4){
        dist[si][sj][i] = 0;
        que.push({si, sj, i});
    }

    while(!que.empty()){
        auto [pi, pj, d] = que.front(); que.pop();
        if(s[pi][pj] == 'o'){
            rep(k, 0, 4){
                if(k != d) continue;
                int ni = pi+(k-1)%2, nj = pj+(k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(s[ni][nj] == '#') continue;
                if(dist[ni][nj][k] != IINF) continue;
                pre[ni][nj][k] = {pi, pj, d};
                dist[ni][nj][k] = dist[pi][pj][d]+1;
                que.push({ni, nj, k});
            }
        }else if(s[pi][pj] == 'x'){
            rep(k, 0, 4){
                if(k == d) continue;
                int ni = pi+(k-1)%2, nj = pj+(k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(s[ni][nj] == '#') continue;
                if(dist[ni][nj][k] != IINF) continue;
                pre[ni][nj][k] = {pi, pj, d};
                dist[ni][nj][k] = dist[pi][pj][d]+1;
                que.push({ni, nj, k});
            }
        }else{
            rep(k, 0, 4){
                int ni = pi+(k-1)%2, nj = pj+(k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(s[ni][nj] == '#') continue;
                if(dist[ni][nj][k] != IINF) continue;
                pre[ni][nj][k] = {pi, pj, d};
                dist[ni][nj][k] = dist[pi][pj][d]+1;
                que.push({ni, nj, k});
            }
        }
    }

    int mi = IINF, min_d = -1;
    rep(i, 0, 4){
        if(mi > dist[gi][gj][i]){
            mi = dist[gi][gj][i];
            min_d = i;
        }
    }
    if(mi == IINF){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        string ss;
        string ULDR = "ULDR";
        int pi = gi, pj = gj;
        while(pi != si || pj != sj){
            assert(inr(0, min_d, 4));
            ss += ULDR[min_d];
            auto [ni, nj, nd] = pre[pi][pj][min_d];
            pi = ni;
            pj = nj;
            min_d = nd;
        }
        reverse(ss.begin(), ss.end());
        cout << ss << endl;
    }

    return 0;
}