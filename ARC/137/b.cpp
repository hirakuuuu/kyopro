#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    vector<int> a(n), ruiseki(n);
    int sum = 0;
    rep(i, 0, n){
        int A; cin >> A;
        if(A) a[i] = 1;
        else a[i] = -1;
        sum += a[i];
        if(i) ruiseki[i] = ruiseki[i-1]+a[i];
        else ruiseki[i] = a[i];
    }

    int m = 0;
    int ans1 = 0;
    rep(i, 0, n){
        ans1 = max(ans1, ruiseki[i]-m);
        m = min(m, ruiseki[i]);

    }
    int ans2 = 0;
    m = 0;
    rep(i, 0, n){
        ans2 = min(ans2, ruiseki[i]-m);
        m = max(m, ruiseki[i]);
    }

    cout << ans1-ans2+1 << endl;

  
  
}