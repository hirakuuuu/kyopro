#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ag

/*
ニムは石の数の排他的論理和を全部とってそれが0になる盤面が負け確定
・[0, 0, ... , 0] の排他的論理和が0
・一回の操作で排他的論理和が0の状態から0の状態にすることはできない
・一回の操作で排他的論理和を0でない状態から0の状態にすることはできる
・一回の操作で必ず石の数が減る
*/



int main(){
    int n; cin >> n;
    vector<int> a(n+1);
    int xor_sum = 0;
    rep(i, 0, n){
        cin >> a[i];
        xor_sum ^= a[i];
    }

    if(xor_sum > 0){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    
    return 0;
}