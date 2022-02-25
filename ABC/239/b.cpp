#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
  ll x; cin >> x;
  if(x >= 0) cout << x/10 << endl;
  else{
    if(x%10) cout << x/10-1 << endl;
    else cout << x/10 << endl;
  }
  return 0;
}