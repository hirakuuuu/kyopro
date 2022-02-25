#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    int t; cin >> t;
    vector<ll> ans;
    while(t--){
        int n, m; cin >> n >> m;
        vector<ll> a, b, c;
        rep(i, 0, n){
            ll x, y; cin >> x >> y;
            rep(j, 0, y){
                c[i] = x;
                i++;
            }
        }
        b[0] = c[0];
        a[0] = b[0];
        ll maxa = a[0];
        rep(i, 1, n){
            b[i] = b[i-1] + c[i];
            a[i] = a[i-1] + b[i];
            if(a[i] > maxa) maxa = a[i];
        }
        ans.push_back(maxa);
    }
    for(auto aa: ans){
        cout << aa << endl;
    }
}