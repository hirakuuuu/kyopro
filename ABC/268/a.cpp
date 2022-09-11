#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc268/tasks/abc268_a

int main(){
    int cnt = 0;
    map<int, bool> m;
    rep(i, 0, 5){
        int a; cin >> a;
        if(m[a]) continue;
        m[a] = true;
        cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}