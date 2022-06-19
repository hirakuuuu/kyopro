#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc142/tasks/arc142_b

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        if(i%2 == 0){
            rep(j, 1, n+1){
                cout << (i/2)*n+j << " ";
            }
        }else{
            rep(j, 1, n+1){
                cout << n*(n-(i+1)/2)+j << " ";
            }
        }
        cout << endl;
    }

    
    return 0;
}