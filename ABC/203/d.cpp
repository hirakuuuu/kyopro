#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    int ng = -1, ok = 0;
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            cin >> a[i][j];
            ok = max(ok, a[i][j]);
        }
    }
    while(ok > ng+1){
        int x = (ok+ng)/2;
        vector<vector<int>> s(n+1, vector<int>(n+1));
        rep(i, 1, n+1){
            rep(j, 1, n+1){
                if(a[i][j] > x) s[i][j] = s[i][j-1]+s[i-1][j]-s[i-1][j-1]+1;
                else s[i][j] = s[i][j-1]+s[i-1][j]-s[i-1][j-1];
            }
        }
        bool f = false;
        rep(i, k, n+1){
            rep(j, k, n+1){
                if(s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k] < k*k/2+1) f = true;
            }
        }
        if(f) ok = x;
        else ng = x;
    }
    cout << ok << endl;
  
}