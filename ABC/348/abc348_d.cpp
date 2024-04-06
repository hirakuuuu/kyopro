#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h);
    rep(i, 0, h) cin >> a[i];
    vector<int> s(2), t(2);
    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][j] == 'S'){
                s[0] = i;
                s[1] = j;
            }
            if(a[i][j] == 'T'){
                t[0] = i;
                t[1] = j;
            }
        }
    }
    int n; cin >> n;
    vector<int> r(n), c(n), e(n+2);
    map<pair<int, int>, bool> ene;
    map<pair<int, int>, int> id;
    rep(i, 0, n){
        cin >> r[i] >> c[i] >> e[i];
        r[i]--, c[i]--;
        ene[{r[i], c[i]}] = true;
        id[{r[i], c[i]}] = i;
    }
    r.push_back(s[0]);
    r.push_back(t[0]);
    c.push_back(s[1]);
    c.push_back(t[1]);
    if(ene[{s[0], s[1]}]) e[n] = e[id[{s[0], s[1]}]];
    if(ene[{t[0], t[1]}]) e[n+1] = e[id[{t[0], t[1]}]];
    ene[{s[0], s[1]}] = true;
    ene[{t[0], t[1]}] = true;
    vector<vector<int>> seen(h, vector<int>(w));
    seen[s[0]][s[1]] = true;
    queue<int> que;
    que.push(n);
    while(!que.empty()){
        int q = que.front(); que.pop();
        queue<pair<int, int>> nque;
        nque.push({r[q], c[q]});
        vector<vector<int>> dist(h, vector<int>(w, -1));
        dist[r[q]][c[q]] = 0;
        while(!nque.empty()){
            auto [cr, cc] = nque.front(); nque.pop();
            if(ene[{cr, cc}] && !seen[cr][cc]){
                seen[cr][cc] = true;
                que.push(id[{cr, cc}]);
            }
            if(dist[cr][cc] >= e[q]) continue;
            rep(k, 0, 4){
                int nr = cr+(k-1)%2, nc = cc+(k-2)%2;
                if(inr(0, nr, h) && inr(0, nc, w) && a[nr][nc] != '#' && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[cr][cc]+1;
                    nque.push({nr, nc});
                }
            }
        }
    }


    if(seen[t[0]][t[1]]) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}