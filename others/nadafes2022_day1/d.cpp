#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_d

int main(){
    int n; cin >> n;
    if(n == 1){
        cout << 0 << endl;
    }else if(n%2){
        cout << -1 << endl;
    }else{
        cout << 0;
        rep(i, 1, n){
            if(i%2) cout << " " << i;
            else cout << " " << n-i;
        }
        cout << endl;
    }
    
    return 0;
}