#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc142/tasks/arc142_c

int main(){
    int n; cin >> n;
    vector<vector<int>> d(3, vector<int>(n+1));
    rep(i, 3, n+1){
        cout << "? 1 " << i << endl;
        cin >> d[1][i];
    }
    rep(i, 3, n+1){
        cout << "? 2 " << i << endl;
        cin >> d[2][i];
    }
    bool f = true;
    int ans = 1000, u = 0, v = 0;
    rep(i, 3, n+1){
        if(abs(d[1][i]-d[2][i]) != 1) f = false;
        ans = min(ans, d[1][i]+d[2][i]);
        if(d[1][i]+d[2][i] == 3 and !u) u = v = i;
        else if(d[1][i]+d[2][i] == 3) v = i;
    }
    if(f){
        cout << "? " << u << " " << v << endl;
        int dist; cin >> dist;
        if(dist == 1) cout << "! 3" << endl;
        else cout << "! 1" << endl;
    }else{
        cout << "! " << ans << endl; 
    }

    return 0;
}