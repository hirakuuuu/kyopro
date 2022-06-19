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
        int m, n, p; cin >> m >> n >> p;
        if(n*n+m*m+p*p == 0) break;

        vector<bool> is_inf(m+1, false);
        is_inf[p] = true;
        int cnt = 1;
        rep(i, 0, n){
            int x, y; cin >> x >> y;
            if(is_inf[x] + is_inf[y] == 1){
                is_inf[x] = is_inf[y] = true;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}