#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc252/tasks/abc252_c

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    int ans = 10000000;

    rep(i, 0, 10){
        vector<int> cnt(10);
        rep(j, 0, n){
            rep(k, 0, 10){
                if(s[j][k] == '0'+i) cnt[k]++;
            }
        }

        int max_cnt = 0, max_j = 0;
        rep(j, 0, 10){
            if(max_cnt <= cnt[j]){
                max_cnt = cnt[j];
                max_j = j;
            }
        }
        ans = min(ans, (max_cnt-1)*10+max_j);
    }
    cout << ans << endl;
    
    return 0;
}