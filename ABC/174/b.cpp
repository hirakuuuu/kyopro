#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc174/tasks/abc174_b

int main(){
    int n, d; cin >> n >> d;
    int cnt = 0;
    rep(i, 0, n){
        double x, y ; cin >> x >> y;
        if(sqrt(x*x+y*y) <= d) cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}