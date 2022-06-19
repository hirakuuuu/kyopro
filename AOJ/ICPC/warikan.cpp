#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<int> a(101);

int main(){
    
    while(true){
        int n, m; cin >> n >> m;
        if(n+m == 0) break;
        int ans = 0;
        rep(i, 0, n){
            cin >> a[i];
            ans += min(a[i], m/n);
        }
        cout << ans << endl;
    }
    
    return 0;
}