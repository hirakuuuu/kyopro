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
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    int ans1 = 0, ans2 = 0;
    bool f = false;
    rep(i, 0, n){
        f = true;
        rep(j, 0, n){
            if(i == j){
                if(a[i] == b[j]) ans1++;
            }else{
                if(f and a[i] == b[j]){
                    ans2++;
                    f = false;
                }
            }
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}