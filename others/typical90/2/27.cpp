#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_aa

int main(){
    int n; cin >> n;
    map<string, int> m;
    rep(i, 0, n){
        string s; cin >> s;
        if(m[s]) continue;
        m[s] = 1;
        cout << i+1 << endl;
    }
    
    return 0;
}