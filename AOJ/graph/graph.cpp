#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
グラフ G=(V, E) の表現方法には隣接リストによる表現と隣接行列による表現があります。

隣接リストの表現では、Vの各頂点に対して1個、合計|V|個のリストでグラフを表します。
頂点uに対して、隣接リストのu個目はuと隣接する全ての頂点からなります。

隣接行列表現では、頂点iから頂点jへ辺がある場合、a_ijが1、無い場合0であるような|V|×|V|の行列Aでグラフを表します。

隣接行列表現の長所
・頂点同士の関係を定数時間で確認できる
・辺の追加や削除を簡単かつ効率的に行うことができる
隣接行列表現の短所
・頂点の数の二乗に比例するメモリを消費する、辺の数が少ない場合は、メモリを無駄にすることになる
・1つの隣接行列では、頂点uから頂点vへの関係を1つしか記録できない
*/


int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        int j, k; cin >> j >> k;
        while(k--){
            int b; cin >> b;
            a[j-1][b-1] = 1;
        }
    }
    rep(i, 0, n){
        rep(j, 0, n){
            if(j > 0) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
}