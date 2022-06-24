#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/1640

int main(){
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        vector<int> d(n);
        rep(i, 0, n) cin >> d[i];

        int ans = 0;
        rep(i, 0, n-1){
            int cnt = 0;
            if(d[i] == 2){
                while(i < n-1 and d[i] == 2 and d[i+1] == 0){
                    i += 2;
                    cnt++;
                }
                if(cnt > 1) ans += cnt-1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}