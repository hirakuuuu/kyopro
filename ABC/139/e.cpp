#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc139/tasks/abc139_e

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i, 0, n){
        rep(j, 0, n-1){
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<int> next(n), played(n);
    int ans = 0;
    bool f = true;
    while(true){
        f = true;
        rep(i, 0, n) played[i] = 0;
        rep(i, 0, n){
            if(played[i] or next[i] == n-1) continue;
            int e = a[i][next[i]];
            if(played[e]) continue;
            if(a[e][next[e]] == i){
                played[i] = played[e] = 1;
                next[i]++, next[e]++;
                f = false;
            }
        }
        if(f) break;
        ans++;
    }

    rep(i, 0, n){
        if(next[i] != n-1){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}