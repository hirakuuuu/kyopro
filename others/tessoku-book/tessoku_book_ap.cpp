#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ap


int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    vector<vector<int>> cnt(101, vector<int>(101));
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        cnt[a[i]][b[i]]++;
    }

    int ans = 0;

    rep(i, 1, 101){
        rep(j, 1, 101){
            int total = 0;
            rep(ii, i, min(i+k, 100)+1){
                rep(jj, j, min(j+k, 100)+1){
                    total += cnt[ii][jj];
                }
            }
            ans = max(ans, total);
        }
    }
    cout << ans << endl;


    
    return 0;
}