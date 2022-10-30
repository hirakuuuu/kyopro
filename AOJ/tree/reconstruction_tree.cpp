#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


/*
https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_D

先行順巡回、中間順巡回でたどった配列が与えられるので、後行順巡回でたどった配列を出力する
先：1 2 3 4 5
中：3 2 4 1 5

考察：
先行順巡回の先頭は必ず根になる。
中間順巡回の列を根で区切ると、左は根の左部分木、右は根の右部分木を構成するノードのみになる。
よく見ると、先行順巡回は、根＋(根の左部分木の要素)＋(根の右部分木の要素)という並びになっている。
ということは...
*/

int pos;
vector<int> pre_tw, ino_tw, pos_tw;
// 木の復元と後行順巡回の生成を両方一気にやる
void rec(int l, int r){
    if(l >= r) return;
    int c = pre_tw[pos++];
    int m = distance(ino_tw.begin(), find(ino_tw.begin(), ino_tw.end(), c));
    // 後行順巡回なので、左部分木、右部分木、根の順でpush_backされるようにする
    rec(l, m);
    rec(m+1, r);
    pos_tw.push_back(c);
}

int main(){
    int n; cin >> n;
    pre_tw.resize(n);
    ino_tw.resize(n);
    rep(i, 0, n) cin >> pre_tw[i];
    rep(i, 0, n) cin >> ino_tw[i];
    pos = 0;

    rec(0, n);
    
    rep(i, 0, n){
        if(i > 0) cout << " ";
        cout << pos_tw[i];
    }
    cout << endl;
}