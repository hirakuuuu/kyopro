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
    while(t--){
        int h, w; cin >> h >> w;
        int a, b; cin >> a >> b;
        int p, q; cin >> p >> q;
        int ud = p-a, lr = q-b;
        if(h == 1){
            if(lr) cout << -1 << endl;
            else cout << 0 << endl;
        }else if(w == 1){
            if(ud >= 0) cout << ud << endl;
            else cout << -1 << endl;
        }else{
            if(p >= a-abs(lr)){
                cout << 2*abs(lr)+p-a << endl;
            }else{
                if((a-abs(lr)-p)%2) cout << a-p+2 << endl;
                else cout << a-p << endl;
            }
        }
    }
    return 0;
}