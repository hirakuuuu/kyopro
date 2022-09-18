#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_b

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;

    string t;
    rep(i, 0, n){
        if(s[i] == s[k-1]) t += s[i];
        else t += '*';
    }

    cout << t << endl;
    
    return 0;
}