#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_d

/*
縦と横の合計　→　前計算で計算量を減らす
・先に各行の合計、各列の合計を計算しておく
・出力は (行の合計)+(列の合計)-(マスの値) とすることでO(1)で計算できる
*/

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<int> sum_h(h), sum_w(w);
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
            sum_h[i] += a[i][j];
            sum_w[j] += a[i][j];
        }
    }
    
    rep(i, 0, h){
        rep(j, 0, w){
            if(j) cout << ' ';
            cout << sum_h[i]+sum_w[j]-a[i][j];
        }
        cout << endl;
    }
    
    return 0;
}