#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_x

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    int sum_g = 0;
    rep(i, 0, n){
        cin >> b[i];
        sum_g += abs(b[i]-a[i]);
    }

    if(k-sum_g >= 0 and (k-sum_g)%2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;    
    return 0;
}