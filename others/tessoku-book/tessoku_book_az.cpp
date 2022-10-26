#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_az

int main(){
    int q; cin >> q;
    queue<string> que;

    while(q--) {
        int t; cin >> t;
        if(t == 1){
            string s; cin >> s;
            que.push(s);
        }else if(t == 2) {
            cout << que.front() << "\n";
        }else {
            que.pop();
        }
    }

    
    return 0;
}