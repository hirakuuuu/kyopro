#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc115/tasks/arc115_c

int main(){
    int n; cin >> n;
    vector<int> a(n+1, 1);
    rep(i, 2, n+1){
        int max_a = 1;
        for(int j = 1; j*j <= i; j++){
            if(i%j == 0){
                max_a = max(max_a, max(a[j], a[i/j]));
            }
        }
        a[i] = max_a+1;
    }
    rep(i, 1, n+1){
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}