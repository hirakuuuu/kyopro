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
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int h, w; cin >> h >> w;
    // assert(inr(1, h, 6) && inr(1, w, 6));
    
    // 辺の本数が 3 の倍数でないとダメ
    if(!(h == w && (h%3 == 0 || h%3 == 2))){
        cout << "No" << endl;
        return 0;
    }

    // h = w = 5+6k (k >= 0) の場合 
    if((h%6 == 5 || h%6 == 3) && h == w){
        vector<vector<char>> grid(h, vector<char>(w, '.'));
        auto solve = [&](auto solve, ll l, ll r) -> void {
            if(l+1 >= r) return;
            rep(i,l,r-1) grid[i][l] = '^';
            rep(i,l,r-1) grid[r-1][i] = '<';
            rep(i,l,r-1) grid[i+1][r-1] = 'v';
            rep(i,l,r-1) grid[l][i+1] = '>';
            if(r-l < 5) return;
            l++; r--;
            rep(i,l,r) if((i-l)%2 == 1) grid[i][l] = '>';
            rep(i,l,r) if((i-l)%2 == 1) grid[r-1][i] = '^';
            rep(i,l,r) if((i-l)%2 == 1) grid[i][r-1] = '<';
            rep(i,l,r) if((i-l)%2 == 1) grid[l][i] = 'v';
            l++; r--;
            rep(i,l,r) if((i-l)%2 == 1) grid[i][l] = '<';
            rep(i,l,r) if((i-l)%2 == 1) grid[r-1][i] = 'v';
            rep(i,l,r) if((i-l)%2 == 1) grid[i][r-1] = '>';
            rep(i,l,r) if((i-l)%2 == 1) grid[l][i] = '^';
            solve(solve, l+1, r-1);
        };
        solve(solve, 0, h);
        cout << "Yes" << endl;
        rep(i,0,h){
            rep(j,0,w) cout << grid[i][j];
            cout << endl;
        }
        return 0;
    }
    

    cout << "No" << endl;
    return 0;
}