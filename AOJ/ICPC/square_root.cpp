#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    while(true){
        int n, m; cin >> n >> m;
        if(n+m == 0) break;

        vector<int> h(n+1), w(m+1);
        map<int, int> mp;
        rep(i, 1, n+1){
            cin >> h[i];
            h[i] += h[i-1]; 
        }
           
        rep(i, 1, m+1){
            cin >> w[i];
            w[i] += w[i-1];
        }

        rep(i, 0, m+1){
            rep(j, i+1, m+1){
                mp[w[j]-w[i]]++;
            }
        }
        int ans = 0;
        rep(i, 0, n+1){
            rep(j, i+1, n+1){
                ans += mp[h[j]-h[i]];
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}