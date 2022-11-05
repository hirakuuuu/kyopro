#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc276/tasks/abc276_d

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<int>> cnt(n, vector<int>(4));
    vector<int> min_cnt(4, 100);
    rep(i, 0, n){
        int b = a[i];
        rep(j, 2, 4){
            while(b%j == 0){
                b /= j;
                cnt[i][j]++;
            }
            min_cnt[j] = min(min_cnt[j], cnt[i][j]);
        }
    }

    int ans = 0;
    rep(i, 0, n){
        rep(j, 2, 4){
            rep(k, 0, cnt[i][j]-min_cnt[j]){
                a[i] /= j;
                ans++;
            }
        }
    }

    bool f = true;
    rep(i, 1, n) f &= (a[0] == a[i]);

    if(f) cout << ans << endl;
    else cout << -1 << endl;

    
    return 0;
}