#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


/*
ある計算式に対して、一度計算した結果をメモリに記録しておき、同じ計算を繰り返し行うという無駄を避けつつ、
それらを再利用することにより効率化を図ることは、プログラミングやアルゴリズムの設計を行う上で有効なアプローチである。
再帰呼び出しを必要とする関数は、一度計算した値を記録して返すようにすれば、O(2^n)をO(nm)まで減らせる（あくまで例）
*/

int main(){
    int n; cin >> n;
    vector<int> fib(45);
    fib[0] = fib[1] = 1;
    rep(i, 2, n+1){
        fib[i] = fib[i-1]+fib[i-2];
    }
    cout << fib[n] << endl;
}