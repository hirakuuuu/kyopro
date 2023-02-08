#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_b

/*
n <= 20　→　bit全探索
・1→(, -1→) という対応付けを行う
・前から累積和を取って，値が負になったら正しくないと判定
・正しいものは出力
・辞書順に出力することに注意
    ・数字の小さい順だと, 後ろに０が多い方が優先的に前に来る
    ・それを考慮してかっこ列を作る
    ・もしくは、後でソートする（今回はこれで間に合う）
*/

int main(){
    int n; cin >> n;
    bool flag = true;
    rep(i, 0, 1<<n){
        // 各値の初期化
        int ii = i, sum = 0;
        flag = true;
        vector<int> bit(n, 0);
        rep(j, 0, n){
            bit[n-j-1] = ii%2;
            ii /= 2;
        }

        // 各並びについて正しい括弧列になるか判定
        rep(j, 0, n){
            sum += bit[j]? -1: 1;
            ii /= 2;
            if(sum < 0) flag = false;
        }
        if(sum != 0) flag = false;

        // 正しいならば出力
        if(flag){
            rep(j, 0, n){
                if(bit[j]) cout << ')';
                else cout << '(';
            }
            cout << endl;
        }
    }
    
    return 0;
}