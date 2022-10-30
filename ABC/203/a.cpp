#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int a, b, c; cin >> a >> b >> c;
    if(a == b) cout << c << endl;
    else if(a == c) cout << b << endl;
    else if(b == c) cout << a << endl;
    else cout << 0 << endl;
  
}