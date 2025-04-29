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
    int h, w, x, y; cin >> h >> w >> x >> y; x--, y--;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    string t; cin >> t;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    string UDLR = "UDLR";
    set<pair<int, int>> home;
    for(auto tt: t){
        rep(k, 0, 4){
            if(UDLR[k] == tt){
                int nx = x+dx[k], ny = y+dy[k];
                if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
                if(s[nx][ny] == '#') continue;

                if(s[nx][ny] == '@') home.insert({nx, ny});
                x = nx, y = ny;
            }
        }
    }
    cout << x+1 << ' ' << y+1 << ' ';
    cout << home.size() << endl;
    
    return 0;
}