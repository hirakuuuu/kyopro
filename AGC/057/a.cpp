#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc057/tasks/agc057_a

int main(){
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int o = 1;
        int ans = 0;
        while(10*o <= r){
            o *= 10;
        }

        if(r < 2*o){
            // oと同じ桁の数
            if(o < l){
                ans += r-l+1;
            }else{
                ans += r-o+1;
                // oより桁が下の数
                int cnt = max(r%o, r/10);
                if(l < o/10) ans += o-cnt-1;
                else ans += o-max(cnt, l-1)-1;
            }
        }else{
            ans += r-max(o, l)+1;
        }
        cout << ans << endl;
    }
    
    return 0;
}