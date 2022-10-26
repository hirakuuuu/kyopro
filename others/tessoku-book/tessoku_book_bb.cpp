#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bb

int main(){
    int q; cin >> q;
    map<string, int> m;
    while(q--){
        int t; cin >> t;
        string s; cin >> s;
        if(t == 1){
            int score; cin >> score;
            m[s] = score;
        }else{
            cout << m[s] << endl;
        }
    }
    
    return 0;
}