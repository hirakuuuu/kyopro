#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cs

vector<vector<int>> edit(2005, vector<int>(2005));

int edit_distance(string s, string t){
    int n = s.size(), m = t.size();
    // sが0文字の時、tの文字数分(j)挿入が必要
    rep(j, 0, n+1) edit[j][0] = j;
    rep(i, 1, m+1){
        // tが0文字の時、sの文字数分(i)挿入が必要
        edit[0][i] = i;

        rep(j, 1, n+1){
            // sのj文字目とtのi文字目が一致しているかどうかで置換するかどうかが変わる
            int cost = 0;
            if(s[j-1] != t[i-1]) cost++;
            // 挿入、削除、置換のどれを行うのが最適かでdp
            edit[j][i] = min(edit[j][i-1]+1, min(edit[j-1][i]+1, edit[j-1][i-1]+cost));
        }
    }
    return edit[n][m];
}



int main(){
    string s, t; cin >> s >> t;

    cout << edit_distance(s, t) << endl;
    
    return 0;
}