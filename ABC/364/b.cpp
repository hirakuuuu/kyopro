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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    int si, sj; cin >> si >> sj;
    si--, sj--;
    vector<string> c(h);
    rep(i, 0, h) cin >> c[i];

    string x; cin >> x;
    map<char, pair<int, int>> d;
    d['L'] = {0, -1};
    d['R'] = {0, 1};
    d['U'] = {-1, 0};
    d['D'] = {1, 0};
    for(auto xx: x){
        int ni = si+d[xx].first, nj = sj+d[xx].second;
        if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
        if(c[ni][nj] == '#') continue;
        si = ni, sj = nj;
    }
    cout << si+1 << ' ' << sj+1 << endl;
    return 0;
}