#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc271/tasks/abc271_a

int main(){
    int n; cin >> n;
    vector<char> num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    int cnt = 0;
    while(n/16){
        n -= 16;
        cnt++;
    }

    cout << num[cnt] << num[n] << endl;

    
    return 0;
}