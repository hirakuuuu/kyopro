#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc140/tasks/abc140_c

int main(){
    int n; cin >> n;
    vector<int> b(n-1);
    rep(i, 0, n-1) cin >> b[i];
    int ans = 0;
    ans += b[0]+b[n-2];
    rep(i, 0, n-2){
        ans += min(b[i], b[i+1]);
    }
    cout << ans << endl;

    
    return 0;
}