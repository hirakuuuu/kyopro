#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc165/tasks/abc165_e

int main(){
    int n, m; cin >> n >> m;
    if(n%2 == 1){
        int l = 1, r = n-1;
        rep(i, 0, m){
            cout << l << ' ' << r << "\n";
            l++;
            r--;
        }
    }else{
        int l1 = 1, r1 = n-1;
        int l2 = n/2, r2 = n/2+1;
        rep(i, 0, m){
            if(i%2 == 0){
                cout << l2 << " " << r2 << "\n";
                l2--;
                r2++;
            }else{
                cout << l1 << " " << r1 << "\n";
                l1++;
                r1--;
            }

        } 
    }
    
    return 0;
}