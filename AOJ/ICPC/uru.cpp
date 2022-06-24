#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/2882

int main(){
    while(true){
        int n, l, r; cin >> n >> l >> r;
        if(n*n+l*l+r*r == 0) break;

        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];
        int cnt = 0;

        rep(i, l, r+1){
            bool f1 = false, f2 = false;
            rep(j, 0, n){
                if(i%a[j] == 0){
                    if(!f1 and j%2 == 0) f2 = true;
                    f1 = true;
                }
            }
            if(f1 and f2) cnt++;
            else if(!f1 and n%2 == 0) cnt++;
        }
        cout << cnt << endl;

    }
    
    return 0;
}