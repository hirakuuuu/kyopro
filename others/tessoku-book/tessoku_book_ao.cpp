#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ao

int main(){
    int n; cin >> n;
    string s; cin >> s;
    rep(i, 0, n-2){
        if(s[i] == s[i+1] and s[i] == s[i+2]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout <<"No" << endl;
    
    return 0;
}