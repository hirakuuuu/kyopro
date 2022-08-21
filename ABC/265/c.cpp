#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc265/tasks/abc265_c

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    vector<vector<bool>> seen(h, vector<bool>(w));

    rep(i, 0, h){
        rep(j, 0, w) cin >> g[i][j];
    }

    map<char, int> m;
    m['U'] = 0;
    m['L'] = 1;
    m['D'] = 2;
    m['R'] = 3;

    int i = 0, j = 0;

    while(true){
        seen[i][j] = true;
        int d = m[g[i][j]];

        if(i+(d-1)%2 < 0 or h <= i+(d-1)%2 or j+(d-2)%2 < 0 or w <= j+(d-2)%2){
            printf("%d %d\n", i+1, j+1);
            break;
        }
        if(seen[i+(d-1)%2][j+(d-2)%2]){
            printf("%d\n", -1);
            break;
        }
        i += (d-1)%2;
        j += (d-2)%2;
    }
    
    return 0;
}