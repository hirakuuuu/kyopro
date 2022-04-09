#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc138/tasks/arc138_b

int main(){
    int n; cin >> n;
    vector<int> b(n);
    rep(i, 0, n) cin >> b[i];
    int l = 0, r = n-1, f = 0;
    while(l <= r){
        if((b[r]+f)%2){
            if((b[l]+f)%2){
                cout << "No" << endl;
                return 0;
            }
            l++;
            f ^= 1;
            r--;
        }else{
            r--;
        }
    }

    cout << "Yes" << endl;

    
    return 0;
}