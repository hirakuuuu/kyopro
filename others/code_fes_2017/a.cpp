// https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_b
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
どのような操作でも、順番を入れ替えても結局同じ → 先に行、次に列のボタンを押すことにする
行に対する操作同士は位置を入れ替えても結局同じ → 上から順にボタンを押すことにする
列についても同じ → 右から順にボタンを押すことにする
そうすると，必ず下のような形しか作れない
  012 j  m
0 ■■■■□□□□
1 ■■■■□□□□
2 ■■■■□□□□
  ■■■■□□□□
i □□□□■■■■
n □□□□■■■■
このような形の場合、黒の数は i*j+(n-i)*(m-j) と表せる
  → 0 <= i <= n, 0 <= j <= m　について、i*j+(n-i)*(m-j) == kが成り立つかを調べれば良い
*/

int main(){
    int n, m, k; cin >> n >> m >> k;
    rep(i, 0, n+1){
        rep(j, 0, m+1){
            if(i*j+(n-i)*(m-j) == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}