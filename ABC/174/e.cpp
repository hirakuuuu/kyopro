#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc174/tasks/abc174_e

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int l = 0, r = 0;
    rep(i, 0, n){
        cin >> a[i];
        r = max(r, a[i]);
    }
    while(r > l+1){
        int m = (l+r)/2;
        int cnt = 0;
        rep(i, 0, n){
            cnt += a[i]/m-1;
            if(a[i]%m) cnt++;
        }
        if(cnt <= k) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}