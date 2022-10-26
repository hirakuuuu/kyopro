#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ay

int main(){
    int q; cin >> q;
    stack<string> stc;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            string s; cin >> s;
            stc.push(s);
        }else if(t == 2) {
            cout << stc.top() << "\n";
        }else {
            stc.pop();
        }
    }
    
    return 0;
}