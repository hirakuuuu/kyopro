#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_b

int main(){
    int n; cin >> n;
    string a, b, c; cin >> a >> b >> c;
    int ans = 0;

    rep(i, 0, n){
        if(a[i] == b[i] and b[i] == c[i]) continue;
        else if(a[i] != b[i] and a[i] == c[i]) ans++;
        else if(a[i] != c[i] and a[i] == b[i]) ans++;
        else if(a[i] != b[i] and b[i] == c[i]) ans++;
        else ans += 2;

    }

    cout << ans << endl;
    
    return 0;
}