#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
グリッド系の問題のためのライブラリ
*/

// 範囲チェック
bool check(int i, int j, int h, int w){
    return (i == clamp(i, 0, h-1) and j == clamp(j, 0, w-1));
}

// 上下左右に対する操作
vector<int> dh = {1, 0, -1, 0};
vector<int> dw = {0, 1, 0, -1};

// 周囲８方向に対する操作
vector<int> dh = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> dw = {-1, -1, -1, 0, 0, 1, 1, 1};



int main(){
    
    return 0;
}