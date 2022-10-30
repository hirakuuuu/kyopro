#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc245/tasks/abc245_b

int main(){
    int n; cin >> n; 
    vector<int> a(2002);
    rep(i, 0, n){
        int b; cin >> b;
        a[b] = 1;
    }
    rep(i, 0, 2002){
        if(a[i]) continue;
        cout << i << endl;
        break;
    }
    
    return 0;
}