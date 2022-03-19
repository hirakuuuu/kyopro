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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    bool win = false;
    if(a[n-1]-a[n-2] > 1) win = true;
    else win = (a[n-1] -n-1)%2;
    if(win) cout << "Alice" << endl;
    else cout << "Bob" << endl;


  
}