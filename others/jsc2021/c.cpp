#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c

int main(){
    int a, b; cin >> a >> b;
    int ans = b-a;
    while(ans){
        int l = (ans-a%ans)%ans;
        if(l+ans <= b-a){
            cout << ans << endl;
            return 0;
        }
        ans--;
    }
    
    return 0;
}