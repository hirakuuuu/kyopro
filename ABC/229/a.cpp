#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc229/tasks/abc229_a

char s[2][2];

int main(){
    int cnt = 0;
    rep(i, 0, 2){
        rep(j, 0, 2){
            cin >> s[i][j];
            if(s[i][j] == '#') cnt++;
        }
    }

    if(cnt == 2 and (s[0][0] == '#' and s[1][1] == '#')) cout << "No" << endl;
    else if(cnt == 2 and (s[1][0] == '#' and s[0][1] == '#')) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}