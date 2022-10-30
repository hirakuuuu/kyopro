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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    while(k--){
        vector<int> b(n, 0);
        rep(i, 0, n){
            int l = max(0, i-a[i]);
            int r = min(n-1, i+a[i]);
            b[l]++;
            if(r+1 < n) b[r+1]--;
        }
        rep(i, 1, n) b[i] += b[i-1];
        a = b;
        bool f = true;
        rep(i, 0, n){
            if(a[i] < n) f = false;
        }
        if(f) break;
    }
    rep(i, 0, n){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}