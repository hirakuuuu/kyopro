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
    vector<int> a(2*n+2);
    rep(i, 0, n+1){
        rep(j, 1, 2*n+2){
            if(a[j]) continue;
            a[j] = 1;
            cout << j << endl;
            break;
        }
        int aoki; cin >> aoki;
        a[aoki] = 1;
    }
  
}