#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc251/tasks/abc251_c

int main(){
    int n; cin >> n;
    map<string, int> m;
    int max_t = 0, max_i = 0;
    rep(i, 0, n){
        string s; cin >> s;
        int t; cin >> t;
        if(m[s]) continue;
        m[s] = 1;
        if(max_t < t){
            max_t = t;
            max_i = i+1;
        }
    }
    cout << max_i << endl;
    
    return 0;
}