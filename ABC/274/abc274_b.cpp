#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc274/tasks/abc274_b

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h);
    rep(i, 0, h) cin >> c[i];

    rep(j, 0, w){
        int x = 0;
        rep(i, 0, h){
            if(c[i][j] == '#') x++;
        }
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}