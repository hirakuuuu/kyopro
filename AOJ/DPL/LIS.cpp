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
    vector<int> l(n, 1000000007);
    rep(i, 0, n){
        auto itr = lower_bound(l.begin(), l.end(), a[i]);
        *itr = a[i];
    }
    rep(i, 0, n){
        if(l[i] == 1000000007){
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;

  
}