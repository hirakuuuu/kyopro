#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc272/tasks/abc272_b

int main(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> join(n+1, vector<bool>(n+1));
    vector<int> x(n+1);
    rep(i, 0, m){
        int k; cin >> k;
        rep(j, 1, k+1) cin >> x[j];

        rep(j, 1, k+1){
            rep(l, j+1, k+1){
                join[x[j]][x[l]] = true;
            }
        }
    }

    bool ans = true;

    rep(i, 1, n+1){
        rep(j, i+1, n+1){
            ans &= join[i][j];
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}